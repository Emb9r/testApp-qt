#include "fileworker.h"
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include <QMutex>


FileWorker::FileWorker(const QString &inputPath,
                       const QString &outputPath,
                       const QByteArray &key,
                       QSettings *settings,
                       QObject *parent) : QObject(parent)
{
    setAutoDelete(false);
    this->inputPath = inputPath;
    this->outputPath = outputPath;
    this->key = key;
    this->settings = settings;

}

void FileWorker::run()
{
    if (key.isEmpty())
    {
        emit error("Ключ не задан");
        emit finished();
        return;
    }

    int actionSettings = settings->value("AppSettings/action", 0).toInt();
    bool deleteFile = settings->value("AppSettings/deleteFile", false).toBool();

    QFile inputFile(inputPath);    
    if (!inputFile.open(QIODevice::ReadOnly))
    {
        emit error("Не удалось открыть входной файл: " + inputFile.errorString());
        emit finished();
        return;
    }

    qint64 totalSize = inputFile.size();
    if (totalSize <= 0)
    {
        emit error("Файл пустой или повреждён: " + inputPath);
        inputFile.close();
        emit progressChanged(100);
        emit finished();
        return;
    }

    QString finalOutputPath = outputPath;
    if (actionSettings == 1)
    {
        QFileInfo fileInfo(outputPath);
        QString baseName = fileInfo.completeBaseName();
        QString suffix = fileInfo.suffix();
        QString dirPath = fileInfo.path();

        int copyNumber = 1;
        do
        {
            finalOutputPath = dirPath + "/" + baseName + "_copy_" + QString::number(copyNumber);
            if (!suffix.isEmpty())
            {
                finalOutputPath += "." + suffix;
            }
            copyNumber++;
        } while (QFile::exists(finalOutputPath));
    }

    QString tempPath = finalOutputPath + ".tmp";
    QFile outputFile(tempPath );
    if (!outputFile.open(QIODevice::WriteOnly))
    {
        emit error("Не удалось открыть выходной файл: " + outputFile.errorString());
        inputFile.close();
        emit finished();
        return;
    }

    const qint64 blockSize = qMin<qint64>(4096 * 1024, totalSize / 100);
    qint64 processedSize = 0;

    while (!inputFile.atEnd() && !m_stop)
    {
        QByteArray buffer = inputFile.read(blockSize);
        if (buffer.isEmpty() && inputFile.error() != QFile::NoError)
        {
            emit error("Ошибка при чтении входного файла: " + inputFile.errorString());
            break;
        }

        for (int i = 0; i < buffer.size(); ++i)
        {
            buffer[i] = buffer[i] ^ key[(processedSize + i) % key.size()];
        }

        if (outputFile.write(buffer) != buffer.size())
        {
            emit error("Ошибка при записи в выходной файл: " + outputFile.errorString());
            break;
        }

        processedSize += buffer.size();
        int progress = static_cast<int>((processedSize * 100) / totalSize);
        emit progressChanged(qMin(progress, 100));
    }

    inputFile.close();
    outputFile.close();

    if(m_stop)
    {
        QFile::remove(tempPath);
    }

    if (processedSize == totalSize)
    {
        if (QFile::exists(finalOutputPath))
        {
            QFile::remove(finalOutputPath);
        }

        if (!QFile::rename(tempPath, finalOutputPath))
        {
            emit error("Не удалось переименовать временный файл в окончательный");
            emit finished();
            return;
        }

        if (deleteFile)
        {
            if (!QFile::remove(inputPath))
            {
                emit error("Не удалось удалить исходный файл: " + inputPath);
            }
        }
    }

    emit finished();
}

void FileWorker::stop()
{
  m_stop = true;
}
