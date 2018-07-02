/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionOptions;
    QAction *actionQuitter;
    QAction *actionA_Propos;
    QAction *actionA_Propos_de_Qt;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QLineEdit *eFind;
    QPushButton *bFind;
    QPushButton *top400;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *comboBox;
    QPushButton *reload;
    QSpacerItem *horizontalSpacer;
    QFormLayout *formLayout;
    QLabel *label;
    QLabel *downCount;
    QLabel *result;
    QTableWidget *listTorrent;
    QMenuBar *menuBar;
    QMenu *menuMenu;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1414, 619);
        MainWindow->setStyleSheet(QLatin1String("background-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(0, 255, 0);\n"
"selection-color: rgb(0, 0, 0);\n"
"color: rgb(0, 255, 0);"));
        actionOptions = new QAction(MainWindow);
        actionOptions->setObjectName(QStringLiteral("actionOptions"));
        actionQuitter = new QAction(MainWindow);
        actionQuitter->setObjectName(QStringLiteral("actionQuitter"));
        actionA_Propos = new QAction(MainWindow);
        actionA_Propos->setObjectName(QStringLiteral("actionA_Propos"));
        actionA_Propos_de_Qt = new QAction(MainWindow);
        actionA_Propos_de_Qt->setObjectName(QStringLiteral("actionA_Propos_de_Qt"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        eFind = new QLineEdit(centralWidget);
        eFind->setObjectName(QStringLiteral("eFind"));

        horizontalLayout->addWidget(eFind);

        bFind = new QPushButton(centralWidget);
        bFind->setObjectName(QStringLiteral("bFind"));
        bFind->setMaximumSize(QSize(150, 16777215));
        bFind->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;    \n"
"	background-color: rgb(0, 0, 0);\n"
"    min-width: 80px;	\n"
"	color: rgb(0, 255, 0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   \n"
"	background-color: rgb(0, 255, 0);\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(0, 255, 0);\n"
"}\n"
"QPushButton:disabled{\n"
"	background-color: rgb(25, 25, 25);\n"
"	color: rgb(0, 255, 0);\n"
"    border: 0px solid #8f8f91;\n"
"}"));

        horizontalLayout->addWidget(bFind);

        top400 = new QPushButton(centralWidget);
        top400->setObjectName(QStringLiteral("top400"));
        top400->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;    \n"
"	background-color: rgb(0, 0, 0);\n"
"    min-width: 80px;	\n"
"	color: rgb(0, 255, 0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   \n"
"	background-color: rgb(0, 255, 0);\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(0, 255, 0);\n"
"}\n"
"QPushButton:disabled{\n"
"	background-color: rgb(25, 25, 25);\n"
"	color: rgb(0, 255, 0);\n"
"    border: 0px solid #8f8f91;\n"
"}"));

        horizontalLayout->addWidget(top400);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        horizontalLayout_2->addWidget(comboBox);

        reload = new QPushButton(centralWidget);
        reload->setObjectName(QStringLiteral("reload"));
        reload->setStyleSheet(QLatin1String("QPushButton {\n"
"    border: 2px solid #8f8f91;\n"
"    border-radius: 6px;    \n"
"	background-color: rgb(0, 0, 0);\n"
"    min-width: 80px;	\n"
"	color: rgb(0, 255, 0);\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"   \n"
"	background-color: rgb(0, 255, 0);\n"
"	color: rgb(0, 0, 0);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(0, 255, 0);\n"
"}\n"
"QPushButton:disabled{\n"
"	background-color: rgb(25, 25, 25);\n"
"	color: rgb(0, 255, 0);\n"
"    border: 0px solid #8f8f91;\n"
"}"));

        horizontalLayout_2->addWidget(reload);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        downCount = new QLabel(centralWidget);
        downCount->setObjectName(QStringLiteral("downCount"));

        formLayout->setWidget(0, QFormLayout::FieldRole, downCount);


        gridLayout->addLayout(formLayout, 2, 0, 1, 1);

        result = new QLabel(centralWidget);
        result->setObjectName(QStringLiteral("result"));

        gridLayout->addWidget(result, 3, 0, 1, 1);

        listTorrent = new QTableWidget(centralWidget);
        if (listTorrent->columnCount() < 6)
            listTorrent->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        listTorrent->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        listTorrent->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        listTorrent->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        listTorrent->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        listTorrent->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        listTorrent->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        listTorrent->setObjectName(QStringLiteral("listTorrent"));
        listTorrent->setMinimumSize(QSize(1000, 0));
        listTorrent->setStyleSheet(QLatin1String("QTableView\n"
"{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(0, 255, 0);\n"
"	gridline-color: rgb(53, 53, 53);\n"
"}\n"
"::section\n"
"{\n"
"	background-color: rgb(0, 0, 0);\n"
"	color: rgb(0, 255, 0);\n"
"}\n"
"::horizontalheader\n"
"{\n"
"	color: rgb(0,0,0);\n"
"}\n"
"::disabled\n"
"{\n"
"	background-color: rgb(20, 20, 20);\n"
"	color: rgb(0,0,0);\n"
"}"));
        listTorrent->setCornerButtonEnabled(true);
        listTorrent->horizontalHeader()->setProperty("showSortIndicator", QVariant(false));
        listTorrent->verticalHeader()->setVisible(false);

        gridLayout->addWidget(listTorrent, 4, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1414, 25));
        menuMenu = new QMenu(menuBar);
        menuMenu->setObjectName(QStringLiteral("menuMenu"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menuMenu->menuAction());
        menuMenu->addSeparator();
        menuMenu->addAction(actionOptions);
        menuMenu->addAction(actionA_Propos);
        menuMenu->addAction(actionA_Propos_de_Qt);
        menuMenu->addSeparator();
        menuMenu->addAction(actionQuitter);

        retranslateUi(MainWindow);
        QObject::connect(eFind, SIGNAL(returnPressed()), bFind, SLOT(click()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "YggTorrent Downloader", Q_NULLPTR));
        actionOptions->setText(QApplication::translate("MainWindow", "Options", Q_NULLPTR));
        actionQuitter->setText(QApplication::translate("MainWindow", "Quitter", Q_NULLPTR));
        actionA_Propos->setText(QApplication::translate("MainWindow", "A Propos", Q_NULLPTR));
        actionA_Propos_de_Qt->setText(QApplication::translate("MainWindow", "A Propos de Qt", Q_NULLPTR));
        eFind->setPlaceholderText(QApplication::translate("MainWindow", "Recherche", Q_NULLPTR));
        bFind->setText(QApplication::translate("MainWindow", "Rechercher", Q_NULLPTR));
        top400->setText(QApplication::translate("MainWindow", "Top 400", Q_NULLPTR));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Tout", Q_NULLPTR)
         << QApplication::translate("MainWindow", "film", Q_NULLPTR)
         << QApplication::translate("MainWindow", "musique", Q_NULLPTR)
         << QApplication::translate("MainWindow", "application", Q_NULLPTR)
         << QApplication::translate("MainWindow", "ebook", Q_NULLPTR)
         << QApplication::translate("MainWindow", "jeux video", Q_NULLPTR)
        );
        reload->setText(QApplication::translate("MainWindow", "  Recharger T\303\251l\303\251chargement  ", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "T\303\251l\303\251chargement en cours :", Q_NULLPTR));
        downCount->setText(QApplication::translate("MainWindow", "0", Q_NULLPTR));
        result->setText(QString());
        QTableWidgetItem *___qtablewidgetitem = listTorrent->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MainWindow", "Nom", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = listTorrent->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MainWindow", "Type", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = listTorrent->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("MainWindow", "Age", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = listTorrent->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("MainWindow", "Taille", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem4 = listTorrent->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("MainWindow", "Seeder", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem5 = listTorrent->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("MainWindow", "Lien", Q_NULLPTR));
        menuMenu->setTitle(QApplication::translate("MainWindow", "Menu", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
