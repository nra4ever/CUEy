/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *impBu;
    QFrame *line;
    QLabel *forLab;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *vinylRad;
    QRadioButton *cdRad;
    QFrame *line_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *inLab;
    QSpacerItem *horizontalSpacer;
    QLabel *outLab;
    QFrame *line_3;
    QGridLayout *gridLayout_2;
    QLabel *cueLab;
    QFrame *line_7;
    QProgressBar *progressBar;
    QFrame *line_2;
    QHBoxLayout *horizontalLayout_2;
    QListView *inView;
    QFrame *line_4;
    QGridLayout *gridLayout;
    QPushButton *goBu;
    QPushButton *clearBu;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QSpacerItem *verticalSpacer_3;
    QFrame *line_5;
    QListView *outView;
    QLabel *label;
    QTextBrowser *cmdout;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1112, 854);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QIcon icon;
        icon.addFile(QStringLiteral("icon.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        centralwidget->setLayoutDirection(Qt::LeftToRight);
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        impBu = new QPushButton(centralwidget);
        impBu->setObjectName(QStringLiteral("impBu"));

        horizontalLayout->addWidget(impBu);


        verticalLayout->addLayout(horizontalLayout);

        line = new QFrame(centralwidget);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line);

        forLab = new QLabel(centralwidget);
        forLab->setObjectName(QStringLiteral("forLab"));

        verticalLayout->addWidget(forLab);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        vinylRad = new QRadioButton(centralwidget);
        vinylRad->setObjectName(QStringLiteral("vinylRad"));

        horizontalLayout_4->addWidget(vinylRad);

        cdRad = new QRadioButton(centralwidget);
        cdRad->setObjectName(QStringLiteral("cdRad"));

        horizontalLayout_4->addWidget(cdRad);


        verticalLayout->addLayout(horizontalLayout_4);

        line_8 = new QFrame(centralwidget);
        line_8->setObjectName(QStringLiteral("line_8"));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_8);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        inLab = new QLabel(centralwidget);
        inLab->setObjectName(QStringLiteral("inLab"));

        horizontalLayout_3->addWidget(inLab);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        outLab = new QLabel(centralwidget);
        outLab->setObjectName(QStringLiteral("outLab"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(outLab->sizePolicy().hasHeightForWidth());
        outLab->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(outLab);


        verticalLayout->addLayout(horizontalLayout_3);

        line_3 = new QFrame(centralwidget);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout->addWidget(line_3);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        cueLab = new QLabel(centralwidget);
        cueLab->setObjectName(QStringLiteral("cueLab"));
        cueLab->setAlignment(Qt::AlignCenter);

        gridLayout_2->addWidget(cueLab, 4, 0, 1, 1);

        line_7 = new QFrame(centralwidget);
        line_7->setObjectName(QStringLiteral("line_7"));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_7, 3, 0, 1, 1);

        progressBar = new QProgressBar(centralwidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(0);

        gridLayout_2->addWidget(progressBar, 6, 0, 1, 1);

        line_2 = new QFrame(centralwidget);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        gridLayout_2->addWidget(line_2, 5, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        inView = new QListView(centralwidget);
        inView->setObjectName(QStringLiteral("inView"));
        QSizePolicy sizePolicy2(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(inView->sizePolicy().hasHeightForWidth());
        inView->setSizePolicy(sizePolicy2);

        horizontalLayout_2->addWidget(inView);

        line_4 = new QFrame(centralwidget);
        line_4->setObjectName(QStringLiteral("line_4"));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_4);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        goBu = new QPushButton(centralwidget);
        goBu->setObjectName(QStringLiteral("goBu"));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(goBu->sizePolicy().hasHeightForWidth());
        goBu->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(goBu, 1, 0, 1, 1);

        clearBu = new QPushButton(centralwidget);
        clearBu->setObjectName(QStringLiteral("clearBu"));
        sizePolicy3.setHeightForWidth(clearBu->sizePolicy().hasHeightForWidth());
        clearBu->setSizePolicy(sizePolicy3);

        gridLayout->addWidget(clearBu, 3, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 2, 0, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 0, 0, 1, 1);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_3, 4, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);

        line_5 = new QFrame(centralwidget);
        line_5->setObjectName(QStringLiteral("line_5"));
        line_5->setFrameShape(QFrame::VLine);
        line_5->setFrameShadow(QFrame::Sunken);

        horizontalLayout_2->addWidget(line_5);

        outView = new QListView(centralwidget);
        outView->setObjectName(QStringLiteral("outView"));
        QSizePolicy sizePolicy4(QSizePolicy::Expanding, QSizePolicy::Minimum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(outView->sizePolicy().hasHeightForWidth());
        outView->setSizePolicy(sizePolicy4);

        horizontalLayout_2->addWidget(outView);


        gridLayout_2->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_2);

        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        cmdout = new QTextBrowser(centralwidget);
        cmdout->setObjectName(QStringLiteral("cmdout"));
        sizePolicy4.setHeightForWidth(cmdout->sizePolicy().hasHeightForWidth());
        cmdout->setSizePolicy(sizePolicy4);

        verticalLayout->addWidget(cmdout);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "CUEy", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Drag and drop CUE file into this window or click the button below to import.", Q_NULLPTR));
        impBu->setText(QApplication::translate("MainWindow", "Import CUE File", Q_NULLPTR));
        forLab->setText(QApplication::translate("MainWindow", "Format", Q_NULLPTR));
        vinylRad->setText(QApplication::translate("MainWindow", "Vinyl (Double-sided Media)", Q_NULLPTR));
        cdRad->setText(QApplication::translate("MainWindow", "CD (Single-sided Media)", Q_NULLPTR));
        inLab->setText(QApplication::translate("MainWindow", "Input Files", Q_NULLPTR));
        outLab->setText(QApplication::translate("MainWindow", "Output files", Q_NULLPTR));
        cueLab->setText(QApplication::translate("MainWindow", "Current CUE File: None", Q_NULLPTR));
        goBu->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        clearBu->setText(QApplication::translate("MainWindow", "Clear and Reset", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "Console Log", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
