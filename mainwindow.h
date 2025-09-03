#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QSettings>
#include "workwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_browseButton_clicked();
    void on_acceptButton_clicked();
    void on_singleRunRadioButton_clicked();
    void on_timerRunRadioButton_clicked();
    void handleWorkWindowClosed();

private:
    Ui::MainWindow *ui;
    WorkWindow *workWindow;
    QButtonGroup *firstButtonGroup;
    QButtonGroup *secondButtonGroup;
    QSettings *settings;

    void saveSettings();
    void loadSettings();
};
#endif // MAINWINDOW_H
