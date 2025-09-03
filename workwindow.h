#ifndef WORKWINDOW_H
#define WORKWINDOW_H

#include "fileworker.h"
#include <QDialog>
#include <QSettings>
#include <QProgressBar>
#include <QTimer>
#include <QThreadPool>


namespace Ui {
class WorkWindow;
}

class WorkWindow : public QDialog
{
    Q_OBJECT

public:
    explicit WorkWindow(QWidget *parent = nullptr, QSettings *settings  = nullptr);
    ~WorkWindow();

signals:
    void closed();

private slots:
    void on_browserButton_clicked();
    void updateTime();


protected:
    void closeEvent(QCloseEvent *event) override;

private:
    Ui::WorkWindow *ui;
    QSettings *settings;
    QTimer *timer;
    int timeLeft;
    bool isTimerRunning;
    QByteArray getKey(QString hexString);
    QString inputPath;
    QThreadPool threadPool;
    QSet<QString> activeFiles;
    QVector<FileWorker*> workers;

    void updateFiles(const QString inputDirectory);
};

#endif // WORKWINDOW_H
