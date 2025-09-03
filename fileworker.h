#ifndef FILEWORKER_H
#define FILEWORKER_H

#include <QObject>
#include <QRunnable>
#include <QProgressBar>
#include <QSettings>

class FileWorker : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit FileWorker(const QString &inputPath,
                        const QString &outputPath,
                        const QByteArray &key,
                        QSettings *settings,
                        QObject *parent = nullptr);

    void run() override;
    void stop();

signals:
    void progressChanged(int value);
    void finished();
    void error(QString message);

private:
    QString inputPath;
    QString outputPath;
    QByteArray key;
    QSettings *settings;
    std::atomic<bool> m_stop{false};
};

#endif // FILEWORKER_H
