/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_3;
    QLabel *nameWidgetLabel;
    QSpacerItem *horizontalSpacer_4;
    QFormLayout *formLayout;
    QLabel *fileMaskLabel;
    QLineEdit *fileMaskLineEdit;
    QLabel *deleteInputFilesLabel;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *deleteInputFilesCheckBox;
    QSpacerItem *horizontalSpacer_5;
    QLabel *savePathLabel;
    QLabel *nameReparingActionLabel;
    QHBoxLayout *horizontalLayout_8;
    QRadioButton *overwriteRadioButton;
    QRadioButton *modifyRadioButton;
    QSpacerItem *horizontalSpacer_6;
    QLabel *operatingModeLabel;
    QHBoxLayout *horizontalLayout_6;
    QRadioButton *singleRunRadioButton;
    QRadioButton *timerRunRadioButton;
    QSpacerItem *horizontalSpacer_7;
    QLabel *polIIntervalLabel;
    QHBoxLayout *horizontalLayout_7;
    QSpinBox *pollIntervalSpinBox;
    QSpacerItem *horizontalSpacer_8;
    QLabel *keyLabel;
    QLineEdit *keyLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *savePathLineEdit;
    QPushButton *browseButton;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *acceptButton;
    QSpacerItem *horizontalSpacer;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_3);

        nameWidgetLabel = new QLabel(centralwidget);
        nameWidgetLabel->setObjectName("nameWidgetLabel");

        horizontalLayout->addWidget(nameWidgetLabel);

        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_4);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        fileMaskLabel = new QLabel(centralwidget);
        fileMaskLabel->setObjectName("fileMaskLabel");

        formLayout->setWidget(0, QFormLayout::ItemRole::LabelRole, fileMaskLabel);

        fileMaskLineEdit = new QLineEdit(centralwidget);
        fileMaskLineEdit->setObjectName("fileMaskLineEdit");

        formLayout->setWidget(0, QFormLayout::ItemRole::FieldRole, fileMaskLineEdit);

        deleteInputFilesLabel = new QLabel(centralwidget);
        deleteInputFilesLabel->setObjectName("deleteInputFilesLabel");

        formLayout->setWidget(1, QFormLayout::ItemRole::LabelRole, deleteInputFilesLabel);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        deleteInputFilesCheckBox = new QCheckBox(centralwidget);
        deleteInputFilesCheckBox->setObjectName("deleteInputFilesCheckBox");

        horizontalLayout_4->addWidget(deleteInputFilesCheckBox);

        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_5);


        formLayout->setLayout(1, QFormLayout::ItemRole::FieldRole, horizontalLayout_4);

        savePathLabel = new QLabel(centralwidget);
        savePathLabel->setObjectName("savePathLabel");

        formLayout->setWidget(2, QFormLayout::ItemRole::LabelRole, savePathLabel);

        nameReparingActionLabel = new QLabel(centralwidget);
        nameReparingActionLabel->setObjectName("nameReparingActionLabel");

        formLayout->setWidget(3, QFormLayout::ItemRole::LabelRole, nameReparingActionLabel);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        overwriteRadioButton = new QRadioButton(centralwidget);
        overwriteRadioButton->setObjectName("overwriteRadioButton");

        horizontalLayout_8->addWidget(overwriteRadioButton);

        modifyRadioButton = new QRadioButton(centralwidget);
        modifyRadioButton->setObjectName("modifyRadioButton");

        horizontalLayout_8->addWidget(modifyRadioButton);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_6);


        formLayout->setLayout(3, QFormLayout::ItemRole::FieldRole, horizontalLayout_8);

        operatingModeLabel = new QLabel(centralwidget);
        operatingModeLabel->setObjectName("operatingModeLabel");

        formLayout->setWidget(4, QFormLayout::ItemRole::LabelRole, operatingModeLabel);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        singleRunRadioButton = new QRadioButton(centralwidget);
        singleRunRadioButton->setObjectName("singleRunRadioButton");

        horizontalLayout_6->addWidget(singleRunRadioButton);

        timerRunRadioButton = new QRadioButton(centralwidget);
        timerRunRadioButton->setObjectName("timerRunRadioButton");

        horizontalLayout_6->addWidget(timerRunRadioButton);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_7);


        formLayout->setLayout(4, QFormLayout::ItemRole::FieldRole, horizontalLayout_6);

        polIIntervalLabel = new QLabel(centralwidget);
        polIIntervalLabel->setObjectName("polIIntervalLabel");

        formLayout->setWidget(5, QFormLayout::ItemRole::LabelRole, polIIntervalLabel);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        pollIntervalSpinBox = new QSpinBox(centralwidget);
        pollIntervalSpinBox->setObjectName("pollIntervalSpinBox");

        horizontalLayout_7->addWidget(pollIntervalSpinBox);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_8);


        formLayout->setLayout(5, QFormLayout::ItemRole::FieldRole, horizontalLayout_7);

        keyLabel = new QLabel(centralwidget);
        keyLabel->setObjectName("keyLabel");

        formLayout->setWidget(6, QFormLayout::ItemRole::LabelRole, keyLabel);

        keyLineEdit = new QLineEdit(centralwidget);
        keyLineEdit->setObjectName("keyLineEdit");

        formLayout->setWidget(6, QFormLayout::ItemRole::FieldRole, keyLineEdit);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        savePathLineEdit = new QLineEdit(centralwidget);
        savePathLineEdit->setObjectName("savePathLineEdit");

        horizontalLayout_3->addWidget(savePathLineEdit);

        browseButton = new QPushButton(centralwidget);
        browseButton->setObjectName("browseButton");

        horizontalLayout_3->addWidget(browseButton);


        formLayout->setLayout(2, QFormLayout::ItemRole::FieldRole, horizontalLayout_3);


        gridLayout->addLayout(formLayout, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);

        acceptButton = new QPushButton(centralwidget);
        acceptButton->setObjectName("acceptButton");

        horizontalLayout_2->addWidget(acceptButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 4, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 3, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 21));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        nameWidgetLabel->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        fileMaskLabel->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\320\272\320\260 \320\262\321\205\320\276\320\264\320\275\321\213\321\205 \321\204\320\260\320\271\320\273\320\276\320\262\n"
"(\320\235\320\260\320\277\321\200\320\270\320\274\320\265\321\200 *.txt \320\270\320\273\320\270 testFile.bin)", nullptr));
        deleteInputFilesLabel->setText(QCoreApplication::translate("MainWindow", "\320\243\320\264\320\260\320\273\321\217\321\202\321\214 \320\262\321\205\320\276\320\264\320\275\321\213\320\265 \321\204\320\260\320\271\320\273\321\213 ", nullptr));
        deleteInputFilesCheckBox->setText(QCoreApplication::translate("MainWindow", "\320\224\320\260", nullptr));
        savePathLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\321\203\321\202\321\214 \320\264\320\273\321\217 \321\201\320\276\321\205\321\200\320\260\320\275\320\265\320\275\320\270\321\217", nullptr));
        nameReparingActionLabel->setText(QCoreApplication::translate("MainWindow", "\320\224\320\265\320\271\321\201\321\202\320\262\320\270\321\217 \320\277\321\200\320\270 \320\277\320\276\320\262\321\202\320\276\321\200\320\265\320\275\320\270\320\270 \320\270\320\274\320\265\320\275\320\270", nullptr));
        overwriteRadioButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\267\320\260\320\277\320\270\321\201\321\214", nullptr));
        modifyRadioButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\276\320\264\320\270\321\204\320\270\320\272\320\260\321\206\320\270\321\217", nullptr));
        operatingModeLabel->setText(QCoreApplication::translate("MainWindow", "\320\240\320\265\320\266\320\270\320\274 \321\200\320\260\320\261\320\276\321\202\321\213", nullptr));
        singleRunRadioButton->setText(QCoreApplication::translate("MainWindow", "\320\240\320\260\320\267\320\276\320\262\321\213\320\271 \320\267\320\260\320\277\321\203\321\201\320\272", nullptr));
        timerRunRadioButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276 \321\202\320\260\320\271\320\274\320\265\321\200\321\203", nullptr));
        polIIntervalLabel->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\270\320\276\320\264\320\270\321\207\320\275\320\276\321\201\321\202\321\214 \320\276\320\277\321\200\320\276\321\201\320\260 (\321\201)", nullptr));
        keyLabel->setText(QCoreApplication::translate("MainWindow", "\320\227\320\275\320\260\321\207\320\265\320\275\320\270\320\265 8 \320\261\320\260\320\271\321\202\n"
" (\320\262 16-\320\276\320\271 \321\201\320\270\321\201\321\202\320\265\320\274\320\265)", nullptr));
        browseButton->setText(QCoreApplication::translate("MainWindow", "\320\236\320\261\320\267\320\276\321\200", nullptr));
        acceptButton->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\275\321\217\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
