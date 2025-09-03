#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QButtonGroup>
#include <QFileDialog>
#include <QRegularExpression>
#include <QRegularExpressionValidator>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    firstButtonGroup = new QButtonGroup(this);
    firstButtonGroup->addButton(ui->overwriteRadioButton);
    firstButtonGroup->addButton(ui->modifyRadioButton);
    firstButtonGroup->setId(ui->overwriteRadioButton, 0);
    firstButtonGroup->setId(ui->modifyRadioButton, 1);

    secondButtonGroup = new QButtonGroup(this);
    secondButtonGroup->addButton(ui->singleRunRadioButton);
    secondButtonGroup->addButton(ui->timerRunRadioButton);
    secondButtonGroup->setId(ui->singleRunRadioButton, 0);
    secondButtonGroup->setId(ui->timerRunRadioButton, 1);

    ui->pollIntervalSpinBox->setMinimum(1);
    ui->pollIntervalSpinBox->setMaximum(120);

    QRegularExpression pathRegexp("^([A-Za-z]:)?[\\\\/](?:[^\\:\\/?\"<>|]*[\\\\/])*[^\\:\\/?\"<>|]*$");
    QRegularExpressionValidator *pathValidator = new QRegularExpressionValidator(pathRegexp, this);
    ui->savePathLineEdit->setValidator(pathValidator);

    QRegularExpression bytesRegexp("^[0-9a-fA-F]{1,16}$");
    QRegularExpressionValidator *bytesValidator = new QRegularExpressionValidator(bytesRegexp, this);
    ui->keyLineEdit->setValidator(bytesValidator);

    QString appPath = QCoreApplication::applicationDirPath();
    QString settingsFile = appPath + "/settings.ini";
    settings = new QSettings(settingsFile, QSettings::IniFormat, this);
    loadSettings();


    workWindow = new WorkWindow(nullptr, settings);
    workWindow->setWindowFlags(Qt::Window | Qt::WindowSystemMenuHint |
                               Qt::WindowMinimizeButtonHint |
                               Qt::WindowMaximizeButtonHint |
                               Qt::WindowCloseButtonHint);

    connect(workWindow, &WorkWindow::closed, this, &MainWindow::handleWorkWindowClosed);
}

MainWindow::~MainWindow()
{
    delete workWindow;
    delete settings;
    delete ui;
}

void MainWindow::on_browseButton_clicked()
{
    QString outputDirectory = QFileDialog::getExistingDirectory(
        this,
        "Выберите папку",
        QDir::currentPath(),
        QFileDialog::ShowDirsOnly |
        QFileDialog::DontResolveSymlinks
    );

    if (!outputDirectory.isEmpty())
    {
        ui->savePathLineEdit->setText(outputDirectory);
    }
}


void MainWindow::on_singleRunRadioButton_clicked()
{
    ui->polIIntervalLabel->setVisible(false);
    ui->pollIntervalSpinBox->setVisible(false);
}

void MainWindow::on_timerRunRadioButton_clicked()
{
    ui->polIIntervalLabel->setVisible(true);
    ui->pollIntervalSpinBox->setVisible(true);
}

void MainWindow::saveSettings()
{
    settings->beginGroup("AppSettings");
    settings->setValue("mask", ui->fileMaskLineEdit->text());
    settings->setValue("deleteFile",  ui->deleteInputFilesCheckBox->isChecked());
    settings->setValue("savePath", ui->savePathLineEdit->text());
    settings->setValue("action", firstButtonGroup->id(firstButtonGroup->checkedButton()));
    settings->setValue("mode", secondButtonGroup->id(secondButtonGroup->checkedButton()));
    settings->setValue("time", ui->pollIntervalSpinBox->value());
    settings->setValue("bytes", ui->keyLineEdit->text().toUpper());
    settings->endGroup();
}

void MainWindow::loadSettings()
{
    ui->fileMaskLineEdit->setText(settings->value("AppSettings/mask", "").toString());
    ui->deleteInputFilesCheckBox->setChecked(settings->value("AppSettings/deleteFile", false).toBool());
    ui->savePathLineEdit->setText(settings->value("AppSettings/savePath", "").toString());


    QAbstractButton* firstButton = firstButtonGroup->buttons().constFirst();
    int selectedId = settings->value("AppSettings/action", firstButtonGroup->id(firstButton)).toInt();
    QAbstractButton *button = firstButtonGroup->button(selectedId);
    if (button)
    {
        button->setChecked(true);
    }

    firstButton = secondButtonGroup->buttons().constFirst();
    selectedId = settings->value("AppSettings/mode", secondButtonGroup->id(firstButton)).toInt();
    button = secondButtonGroup->button(selectedId);
    if (button)
    {
        button->setChecked(true);
    }

    if(ui->singleRunRadioButton->isChecked())
    {
        ui->polIIntervalLabel->setVisible(false);
        ui->pollIntervalSpinBox->setVisible(false);
    }

    ui->pollIntervalSpinBox->setValue(settings->value("AppSettings/time", 1).toInt());
    ui->keyLineEdit->setText(settings->value("AppSettings/bytes", "").toString());
}


void MainWindow::on_acceptButton_clicked()
{
    saveSettings();
    hide();
    workWindow->show();
    workWindow->activateWindow();
    workWindow->raise();
}

void MainWindow::handleWorkWindowClosed()
{
    show();
}
