/********************************************************************************
** Form generated from reading UI file 'workwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WORKWINDOW_H
#define UI_WORKWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_WorkWindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_4;
    QLabel *tabkeNameLabel;
    QSpacerItem *horizontalSpacer_3;
    QTableWidget *filesTableWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *chosePathLabel;
    QLineEdit *chosePathLineEdit;
    QPushButton *browserButton;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QLabel *timerLabel;
    QSpacerItem *horizontalSpacer_2;

    void setupUi(QDialog *WorkWindow)
    {
        if (WorkWindow->objectName().isEmpty())
            WorkWindow->setObjectName("WorkWindow");
        WorkWindow->resize(575, 497);
        verticalLayout = new QVBoxLayout(WorkWindow);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_4);

        tabkeNameLabel = new QLabel(WorkWindow);
        tabkeNameLabel->setObjectName("tabkeNameLabel");

        horizontalLayout_3->addWidget(tabkeNameLabel);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_3);


        verticalLayout->addLayout(horizontalLayout_3);

        filesTableWidget = new QTableWidget(WorkWindow);
        filesTableWidget->setObjectName("filesTableWidget");

        verticalLayout->addWidget(filesTableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        chosePathLabel = new QLabel(WorkWindow);
        chosePathLabel->setObjectName("chosePathLabel");

        horizontalLayout->addWidget(chosePathLabel);

        chosePathLineEdit = new QLineEdit(WorkWindow);
        chosePathLineEdit->setObjectName("chosePathLineEdit");

        horizontalLayout->addWidget(chosePathLineEdit);

        browserButton = new QPushButton(WorkWindow);
        browserButton->setObjectName("browserButton");

        horizontalLayout->addWidget(browserButton);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        timerLabel = new QLabel(WorkWindow);
        timerLabel->setObjectName("timerLabel");

        horizontalLayout_2->addWidget(timerLabel);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(WorkWindow);

        QMetaObject::connectSlotsByName(WorkWindow);
    } // setupUi

    void retranslateUi(QDialog *WorkWindow)
    {
        WorkWindow->setWindowTitle(QCoreApplication::translate("WorkWindow", "Dialog", nullptr));
        tabkeNameLabel->setText(QCoreApplication::translate("WorkWindow", "\320\237\321\200\320\276\320\263\321\200\320\265\321\201 \320\276\320\261\321\200\320\260\320\261\320\276\321\202\320\272\320\270 \321\204\320\260\320\271\320\273\320\276\320\262", nullptr));
        chosePathLabel->setText(QCoreApplication::translate("WorkWindow", "\320\222\321\213\320\261\320\265\321\200\320\270\321\202\320\265 \320\277\321\203\321\202\321\214", nullptr));
        browserButton->setText(QCoreApplication::translate("WorkWindow", "\320\236\320\261\320\267\320\276\321\200", nullptr));
        timerLabel->setText(QCoreApplication::translate("WorkWindow", "\320\241\320\273\320\265\320\264\321\203\321\211\320\260\321\217 \320\277\321\200\320\276\320\262\320\265\321\200\320\272\320\260 \321\204\320\260\320\273\320\276\320\262 \321\207\320\265\321\200\320\265\320\267: 0\321\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WorkWindow: public Ui_WorkWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WORKWINDOW_H
