/********************************************************************************
** Form generated from reading UI file 'art_wiz.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ART_WIZ_H
#define UI_ART_WIZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_art_Wiz
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *epdateLayout;
    QHBoxLayout *horizontalLayout;
    QComboBox *procombo;
    QComboBox *epcombo;
    QLabel *datelab;
    QFrame *mainLayout;
    QHBoxLayout *horizontalLayout_2;
    QFrame *subLayout;
    QHBoxLayout *horizontalLayout_4;
    QTableView *tabv;
    QFrame *detLayout;
    QVBoxLayout *verticalLayout_3;
    QFrame *dtlnLayout;
    QVBoxLayout *verticalLayout_4;
    QPushButton *subbut;
    QFrame *lLayout;
    QHBoxLayout *horizontalLayout_8;
    QLabel *lcuren;
    QLabel *lclab;
    QFrame *lcLayout;
    QHBoxLayout *horizontalLayout_7;
    QPlainTextEdit *lcCom;
    QFrame *dnLayout;
    QHBoxLayout *horizontalLayout_3;
    QLabel *dcuren;
    QLabel *dclab;
    QFrame *dcLayout;
    QHBoxLayout *horizontalLayout_6;
    QPlainTextEdit *dcCom;
    QFrame *prevLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *videobut;
    QLabel *prevlab;
    QLabel *prolab;
    QLabel *curstate;

    void setupUi(QWidget *art_Wiz)
    {
        if (art_Wiz->objectName().isEmpty())
            art_Wiz->setObjectName(QStringLiteral("art_Wiz"));
        art_Wiz->resize(980, 451);
        verticalLayout = new QVBoxLayout(art_Wiz);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        epdateLayout = new QFrame(art_Wiz);
        epdateLayout->setObjectName(QStringLiteral("epdateLayout"));
        epdateLayout->setMinimumSize(QSize(0, 0));
        epdateLayout->setMaximumSize(QSize(16777215, 16777215));
        epdateLayout->setStyleSheet(QStringLiteral("background-color: rgb(80, 80, 80);"));
        epdateLayout->setFrameShape(QFrame::NoFrame);
        epdateLayout->setFrameShadow(QFrame::Sunken);
        horizontalLayout = new QHBoxLayout(epdateLayout);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        procombo = new QComboBox(epdateLayout);
        procombo->setObjectName(QStringLiteral("procombo"));
        procombo->setMinimumSize(QSize(60, 40));
        procombo->setMaximumSize(QSize(240, 16777215));
        QFont font;
        font.setFamily(QStringLiteral("Trebuchet MS"));
        font.setPointSize(12);
        font.setBold(false);
        font.setWeight(50);
        procombo->setFont(font);
        procombo->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(procombo);

        epcombo = new QComboBox(epdateLayout);
        epcombo->setObjectName(QStringLiteral("epcombo"));
        epcombo->setMinimumSize(QSize(120, 40));
        epcombo->setMaximumSize(QSize(120, 16777215));
        epcombo->setFont(font);
        epcombo->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout->addWidget(epcombo);

        datelab = new QLabel(epdateLayout);
        datelab->setObjectName(QStringLiteral("datelab"));
        datelab->setMinimumSize(QSize(0, 40));
        QFont font1;
        font1.setFamily(QStringLiteral("Trebuchet MS"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        datelab->setFont(font1);
        datelab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(datelab);


        verticalLayout->addWidget(epdateLayout);

        mainLayout = new QFrame(art_Wiz);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        mainLayout->setStyleSheet(QStringLiteral("background-color: rgb(213, 213, 213);"));
        mainLayout->setFrameShape(QFrame::StyledPanel);
        mainLayout->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(mainLayout);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(2, 2, 2, 2);
        subLayout = new QFrame(mainLayout);
        subLayout->setObjectName(QStringLiteral("subLayout"));
        subLayout->setFrameShape(QFrame::StyledPanel);
        subLayout->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(subLayout);
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(2, 2, 2, 2);
        tabv = new QTableView(subLayout);
        tabv->setObjectName(QStringLiteral("tabv"));
        tabv->setEditTriggers(QAbstractItemView::DoubleClicked);
        tabv->setAlternatingRowColors(true);
        tabv->setSelectionBehavior(QAbstractItemView::SelectRows);
        tabv->setSortingEnabled(true);
        tabv->horizontalHeader()->setCascadingSectionResizes(true);
        tabv->verticalHeader()->setCascadingSectionResizes(true);

        horizontalLayout_4->addWidget(tabv);

        detLayout = new QFrame(subLayout);
        detLayout->setObjectName(QStringLiteral("detLayout"));
        detLayout->setMinimumSize(QSize(320, 0));
        detLayout->setMaximumSize(QSize(320, 16777215));
        detLayout->setFrameShape(QFrame::StyledPanel);
        detLayout->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(detLayout);
        verticalLayout_3->setSpacing(0);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        dtlnLayout = new QFrame(detLayout);
        dtlnLayout->setObjectName(QStringLiteral("dtlnLayout"));
        dtlnLayout->setFrameShape(QFrame::StyledPanel);
        dtlnLayout->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(dtlnLayout);
        verticalLayout_4->setSpacing(2);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(2, 2, 2, 2);
        subbut = new QPushButton(dtlnLayout);
        subbut->setObjectName(QStringLiteral("subbut"));
        subbut->setMinimumSize(QSize(0, 36));
        subbut->setMaximumSize(QSize(16777215, 36));
        subbut->setFont(font1);

        verticalLayout_4->addWidget(subbut);


        verticalLayout_3->addWidget(dtlnLayout);

        lLayout = new QFrame(detLayout);
        lLayout->setObjectName(QStringLiteral("lLayout"));
        lLayout->setFrameShape(QFrame::StyledPanel);
        lLayout->setFrameShadow(QFrame::Raised);
        horizontalLayout_8 = new QHBoxLayout(lLayout);
        horizontalLayout_8->setSpacing(4);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(2, 2, 2, 2);
        lcuren = new QLabel(lLayout);
        lcuren->setObjectName(QStringLiteral("lcuren"));
        lcuren->setFont(font1);
        lcuren->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_8->addWidget(lcuren);

        lclab = new QLabel(lLayout);
        lclab->setObjectName(QStringLiteral("lclab"));
        lclab->setMaximumSize(QSize(16777215, 20));
        lclab->setFont(font1);
        lclab->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        horizontalLayout_8->addWidget(lclab);


        verticalLayout_3->addWidget(lLayout);

        lcLayout = new QFrame(detLayout);
        lcLayout->setObjectName(QStringLiteral("lcLayout"));
        lcLayout->setMinimumSize(QSize(0, 100));
        lcLayout->setMaximumSize(QSize(16777215, 16777215));
        lcLayout->setFrameShape(QFrame::StyledPanel);
        lcLayout->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(lcLayout);
        horizontalLayout_7->setSpacing(2);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(2, 2, 2, 2);
        lcCom = new QPlainTextEdit(lcLayout);
        lcCom->setObjectName(QStringLiteral("lcCom"));
        lcCom->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        lcCom->setReadOnly(true);

        horizontalLayout_7->addWidget(lcCom);


        verticalLayout_3->addWidget(lcLayout);

        dnLayout = new QFrame(detLayout);
        dnLayout->setObjectName(QStringLiteral("dnLayout"));
        dnLayout->setFrameShape(QFrame::StyledPanel);
        dnLayout->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(dnLayout);
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(2, 2, 2, 2);
        dcuren = new QLabel(dnLayout);
        dcuren->setObjectName(QStringLiteral("dcuren"));
        dcuren->setFont(font1);
        dcuren->setAlignment(Qt::AlignBottom|Qt::AlignLeading|Qt::AlignLeft);

        horizontalLayout_3->addWidget(dcuren);

        dclab = new QLabel(dnLayout);
        dclab->setObjectName(QStringLiteral("dclab"));
        dclab->setMaximumSize(QSize(16777215, 20));
        dclab->setFont(font1);
        dclab->setAlignment(Qt::AlignBottom|Qt::AlignRight|Qt::AlignTrailing);

        horizontalLayout_3->addWidget(dclab);

        dclab->raise();
        dcuren->raise();

        verticalLayout_3->addWidget(dnLayout);

        dcLayout = new QFrame(detLayout);
        dcLayout->setObjectName(QStringLiteral("dcLayout"));
        dcLayout->setMaximumSize(QSize(16777215, 16777215));
        dcLayout->setFrameShape(QFrame::StyledPanel);
        dcLayout->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(dcLayout);
        horizontalLayout_6->setSpacing(2);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(2, 2, 2, 2);
        dcCom = new QPlainTextEdit(dcLayout);
        dcCom->setObjectName(QStringLiteral("dcCom"));
        dcCom->setStyleSheet(QLatin1String("\n"
"background-color: rgb(255, 255, 255);"));
        dcCom->setReadOnly(true);

        horizontalLayout_6->addWidget(dcCom);


        verticalLayout_3->addWidget(dcLayout);


        horizontalLayout_4->addWidget(detLayout);


        horizontalLayout_2->addWidget(subLayout);

        prevLayout = new QFrame(mainLayout);
        prevLayout->setObjectName(QStringLiteral("prevLayout"));
        prevLayout->setFrameShape(QFrame::StyledPanel);
        prevLayout->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(prevLayout);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        videobut = new QPushButton(prevLayout);
        videobut->setObjectName(QStringLiteral("videobut"));
        videobut->setMinimumSize(QSize(0, 38));
        videobut->setMaximumSize(QSize(2000, 40));
        videobut->setFont(font);
        videobut->setStyleSheet(QLatin1String("background-color: rgb(80, 80, 80);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout_2->addWidget(videobut);

        prevlab = new QLabel(prevLayout);
        prevlab->setObjectName(QStringLiteral("prevlab"));
        prevlab->setMinimumSize(QSize(164, 105));
        prevlab->setMaximumSize(QSize(164, 105));
        prevlab->setPixmap(QPixmap(QString::fromUtf8("S:/intelture/Pipeline/noPreview.png")));

        verticalLayout_2->addWidget(prevlab);

        prolab = new QLabel(prevLayout);
        prolab->setObjectName(QStringLiteral("prolab"));
        prolab->setMinimumSize(QSize(164, 105));
        prolab->setMaximumSize(QSize(164, 105));
        prolab->setPixmap(QPixmap(QString::fromUtf8("S:/intelture/Pipeline/noPreview.png")));

        verticalLayout_2->addWidget(prolab);


        horizontalLayout_2->addWidget(prevLayout);


        verticalLayout->addWidget(mainLayout);

        curstate = new QLabel(art_Wiz);
        curstate->setObjectName(QStringLiteral("curstate"));
        curstate->setMinimumSize(QSize(0, 40));
        curstate->setMaximumSize(QSize(16777215, 40));
        QFont font2;
        font2.setFamily(QStringLiteral("Trebuchet MS"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        curstate->setFont(font2);
        curstate->setStyleSheet(QLatin1String("background-color: rgb(80, 80, 80);\n"
"color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(curstate);


        retranslateUi(art_Wiz);

        QMetaObject::connectSlotsByName(art_Wiz);
    } // setupUi

    void retranslateUi(QWidget *art_Wiz)
    {
        art_Wiz->setWindowTitle(QApplication::translate("art_Wiz", "art_Wiz", 0));
        datelab->setText(QApplication::translate("art_Wiz", "24/9/2014", 0));
        subbut->setText(QApplication::translate("art_Wiz", "Submit", 0));
        lcuren->setText(QString());
        lclab->setText(QApplication::translate("art_Wiz", "Lead Notes", 0));
        dcuren->setText(QString());
        dclab->setText(QApplication::translate("art_Wiz", "Director Notes", 0));
        videobut->setText(QApplication::translate("art_Wiz", "Video", 0));
        prevlab->setText(QString());
        prolab->setText(QString());
        curstate->setText(QApplication::translate("art_Wiz", "Jinnrise", 0));
    } // retranslateUi

};

namespace Ui {
    class art_Wiz: public Ui_art_Wiz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ART_WIZ_H