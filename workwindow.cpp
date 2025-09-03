#include "workwindow.h"
#include "ui_workwindow.h"
#include <QCloseEvent>
#include <QMessageBox>
#include <QFileDialog>
#include <QScrollBar>
#include <QFile>
#include <QByteArray>
#include <QThread>


WorkWindow::WorkWindow(QWidget *parent, QSettings* settings)
    : QDialog(parent)
    , ui(new Ui::WorkWindow)
{
    timeLeft = 0;
    isTimerRunning = false;
    this->settings = settings;

    ui->setupUi(this);

    ui->chosePathLineEdit->setReadOnly(true);
    ui->filesTableWidget->setColumnCount(2);
    ui->filesTableWidget->setHorizontalHeaderLabels({"Файл", "Статус обработки"});
    ui->filesTableWidget->horizontalHeader()->setStretchLastSection(true);
    ui->filesTableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    auto scrollBar = new QScrollBar(Qt::Vertical, this);
    ui->filesTableWidget->setVerticalScrollBar(scrollBar);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &WorkWindow::updateTime);

    threadPool.setMaxThreadCount(QThread::idealThreadCount());
}

WorkWindow::~WorkWindow()
{
    delete timer;
    delete ui;
}

void WorkWindow::on_browserButton_clicked()
{

    QString inputDirectory = QFileDialog::getExistingDirectory(
        this,
        "Выберите папку для сканирования",
        QDir::currentPath(),
        QFileDialog::ShowDirsOnly |
        QFileDialog::DontResolveSymlinks
    );

    if (inputDirectory.isEmpty()) return;

    ui->chosePathLineEdit->setText(inputDirectory);
    inputPath = inputDirectory;

    if (settings->value("AppSettings/mode", 0).toInt() == 0)
    {
        updateFiles(inputPath);
    }
    else
    {
        if(!isTimerRunning)
        {
            isTimerRunning = true;
            updateFiles(inputPath);
            timeLeft = settings->value("AppSettings/time", 1).toInt();
            QString str = "До нового выбора файла : " + QString::number(timeLeft) + "c";
            ui->timerLabel->setText(str);
            timer->start(1000);
        }
    }
}

void WorkWindow::updateTime()
{
    timeLeft--;
    QString str = "До нового выбора файла : " + QString::number(timeLeft) + "c";
    ui->timerLabel->setText(str);

    if (timeLeft < 0)
    {
        updateFiles(inputPath);
        timeLeft = settings->value("AppSettings/time", 1).toInt();
        str = "До нового выбора файла : " + QString::number(timeLeft) + "c";
        ui->timerLabel->setText(str);
    }
}

QByteArray WorkWindow::getKey(QString hexString)
{
    QByteArray key;

    if (hexString.size() % 2 != 0)
    {
        hexString.prepend("0");
    }

    for (int i = 0; i < hexString.size(); i += 2)
    {
        QString byteString = hexString.mid(i, 2);
        bool ok;
        char byte = static_cast<char>(byteString.toUInt(&ok, 16));
        if (ok)
        {
            key.append(byte);
        }
    }

    while (key.size() < 8)
    {
        key.prepend('\0');
    }

    return key;
}

void WorkWindow::updateFiles(const QString inputDirectory)
{
    QString mask = settings->value("AppSettings/mask", "").toString();
    QDir dir(inputDirectory);

    if (!dir.exists())
    {
        qCritical() << "Директория не существует: " << inputDirectory;
        return;
    }

    QList<QString> filesList =  dir.entryList({mask}, QDir::Files);

    for (const QString& filePath : std::as_const(filesList))
    {
        QFileInfo fileInfo(filePath);
        QString fileName = fileInfo.fileName();

        if (activeFiles.contains(filePath)) continue;
        activeFiles.insert(filePath);


        QTableWidgetItem *pathItem = new QTableWidgetItem(fileName);
        pathItem->setFlags(pathItem->flags() & ~Qt::ItemIsEditable);
        pathItem->setToolTip(filePath);

        int row = ui->filesTableWidget->rowCount();
        ui->filesTableWidget->insertRow(row);
        ui->filesTableWidget->setItem(row, 0, pathItem);

        QProgressBar *progressBar = new QProgressBar();
        progressBar->setRange(0, 100);
        progressBar->setValue(0);
        ui->filesTableWidget->setCellWidget(row, 1, progressBar);


        QString outputPath =  settings->value("AppSettings/savePath", "").toString() + "/" + fileName;
        QByteArray key = getKey(settings->value("AppSettings/bytes", "").toString());

        FileWorker *fileWorker = new FileWorker(filePath, outputPath, key, settings);
        workers.append(fileWorker);

        connect(fileWorker, &FileWorker::progressChanged, progressBar, &QProgressBar::setValue);
        connect(fileWorker, &FileWorker::error, this, [](QString msg)
        {
            qCritical() << msg;
        });
        connect(fileWorker, &FileWorker::finished, this, [this, filePath, fileWorker]()
                {
                    activeFiles.remove(filePath);
                    fileWorker->deleteLater();
                },
                Qt::QueuedConnection);

        threadPool.start(fileWorker);
    }
}

void WorkWindow::closeEvent(QCloseEvent *event)
{
    if (!activeFiles.isEmpty())
    {
        int close = QMessageBox::warning(this,
                                       "Обработка файлов не завершена",
                                       "Выходные файлы не будут сохранены.\nЗавершить программу?",
                                       QMessageBox::Yes | QMessageBox::No,
                                       QMessageBox::No);

        if (close == QMessageBox::Yes)
        {
            for (FileWorker* worker : std::as_const(workers))
            {
                worker->stop();
            }
            threadPool.waitForDone();

            event->accept();
        }
        else
        {
            event->ignore();
        }
        return;
    }

    event->accept();
}
