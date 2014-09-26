/********************************************************************************
** Form generated from reading UI file 'assign_wiz.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ASSIGN_WIZ_H
#define UI_ASSIGN_WIZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_assign_wiz
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *epdateLayout;
    QHBoxLayout *horizontalLayout_2;
    QComboBox *procombo;
    QComboBox *epcombo;
    QLabel *datelab;
    QFrame *asshotbutLayout;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *asbut;
    QPushButton *shbut;
    QFrame *stckLayout_2;
    QVBoxLayout *verticalLayout_2;
    QStackedWidget *stackedWidget;
    QWidget *asPage;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *astabLayout;
    QTabWidget *astabwidg;
    QWidget *modt;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *modtablayout;
    QTableView *modtabv;
    QWidget *rigt;
    QVBoxLayout *verticalLayout_8;
    QVBoxLayout *rigtabayout;
    QTableView *rigtabv;
    QVBoxLayout *asprevLayout;
    QLabel *asprevlab;
    QLabel *asprolab;
    QWidget *shPage;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *shtabLayout;
    QTabWidget *shtabwidg;
    QWidget *prevt;
    QVBoxLayout *verticalLayout_9;
    QVBoxLayout *prevtabLayout;
    QTableView *prevtabv;
    QWidget *blkt;
    QVBoxLayout *verticalLayout_10;
    QVBoxLayout *blktabLayout;
    QTableView *blktabv;
    QWidget *animt;
    QVBoxLayout *verticalLayout_11;
    QVBoxLayout *anitabLayout;
    QTableView *anitabv;
    QWidget *light;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *ligtabLayout;
    QTableView *lighttabv;
    QVBoxLayout *shprevLayout;
    QLabel *shprevlab;
    QLabel *shprolab;
    QLabel *curstate;

    void setupUi(QWidget *assign_wiz)
    {
        if (assign_wiz->objectName().isEmpty())
            assign_wiz->setObjectName(QStringLiteral("assign_wiz"));
        assign_wiz->setWindowModality(Qt::NonModal);
        assign_wiz->resize(800, 500);
        assign_wiz->setStyleSheet(QStringLiteral(""));
        verticalLayout = new QVBoxLayout(assign_wiz);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        verticalLayout->setContentsMargins(2, 4, 4, 4);
        epdateLayout = new QFrame(assign_wiz);
        epdateLayout->setObjectName(QStringLiteral("epdateLayout"));
        epdateLayout->setStyleSheet(QStringLiteral("background-color: rgb(80, 80, 80);"));
        epdateLayout->setFrameShape(QFrame::NoFrame);
        epdateLayout->setFrameShadow(QFrame::Sunken);
        epdateLayout->setLineWidth(0);
        horizontalLayout_2 = new QHBoxLayout(epdateLayout);
        horizontalLayout_2->setSpacing(4);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(2, 2, 2, 2);
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

        horizontalLayout_2->addWidget(procombo);

        epcombo = new QComboBox(epdateLayout);
        epcombo->setObjectName(QStringLiteral("epcombo"));
        epcombo->setMinimumSize(QSize(60, 40));
        epcombo->setMaximumSize(QSize(120, 16777215));
        epcombo->setFont(font);
        epcombo->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        horizontalLayout_2->addWidget(epcombo);

        datelab = new QLabel(epdateLayout);
        datelab->setObjectName(QStringLiteral("datelab"));
        QFont font1;
        font1.setFamily(QStringLiteral("Trebuchet MS"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        datelab->setFont(font1);
        datelab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(datelab);


        verticalLayout->addWidget(epdateLayout);

        asshotbutLayout = new QFrame(assign_wiz);
        asshotbutLayout->setObjectName(QStringLiteral("asshotbutLayout"));
        asshotbutLayout->setStyleSheet(QStringLiteral("background-color: rgb(213, 213, 213);"));
        asshotbutLayout->setFrameShape(QFrame::StyledPanel);
        asshotbutLayout->setFrameShadow(QFrame::Raised);
        horizontalLayout_4 = new QHBoxLayout(asshotbutLayout);
        horizontalLayout_4->setSpacing(4);
        horizontalLayout_4->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(2, 2, 2, 2);
        asbut = new QPushButton(asshotbutLayout);
        asbut->setObjectName(QStringLiteral("asbut"));
        asbut->setMinimumSize(QSize(0, 40));
        QFont font2;
        font2.setFamily(QStringLiteral("Tekton Pro"));
        font2.setPointSize(16);
        font2.setBold(true);
        font2.setWeight(75);
        asbut->setFont(font2);
        asbut->setStyleSheet(QStringLiteral("background-color: rgb(0, 179, 255);"));
        asbut->setCheckable(true);
        asbut->setChecked(true);
        asbut->setDefault(true);
        asbut->setFlat(true);

        horizontalLayout_4->addWidget(asbut);

        shbut = new QPushButton(asshotbutLayout);
        shbut->setObjectName(QStringLiteral("shbut"));
        shbut->setMinimumSize(QSize(0, 40));
        shbut->setFont(font2);
        shbut->setStyleSheet(QStringLiteral("background-color: rgb(0, 85, 68);"));
        shbut->setCheckable(true);
        shbut->setDefault(true);
        shbut->setFlat(true);

        horizontalLayout_4->addWidget(shbut);


        verticalLayout->addWidget(asshotbutLayout);

        stckLayout_2 = new QFrame(assign_wiz);
        stckLayout_2->setObjectName(QStringLiteral("stckLayout_2"));
        stckLayout_2->setStyleSheet(QStringLiteral("background-color: rgb(213, 213, 213);"));
        stckLayout_2->setFrameShape(QFrame::StyledPanel);
        stckLayout_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(stckLayout_2);
        verticalLayout_2->setSpacing(2);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
        stackedWidget = new QStackedWidget(stckLayout_2);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        stackedWidget->setAutoFillBackground(false);
        stackedWidget->setStyleSheet(QStringLiteral(""));
        stackedWidget->setFrameShape(QFrame::Panel);
        stackedWidget->setFrameShadow(QFrame::Sunken);
        asPage = new QWidget();
        asPage->setObjectName(QStringLiteral("asPage"));
        horizontalLayout = new QHBoxLayout(asPage);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        astabLayout = new QHBoxLayout();
        astabLayout->setSpacing(6);
        astabLayout->setObjectName(QStringLiteral("astabLayout"));
        astabwidg = new QTabWidget(asPage);
        astabwidg->setObjectName(QStringLiteral("astabwidg"));
        astabwidg->setFont(font1);
        astabwidg->setAutoFillBackground(false);
        astabwidg->setStyleSheet(QStringLiteral(""));
        astabwidg->setTabShape(QTabWidget::Rounded);
        astabwidg->setIconSize(QSize(16, 16));
        astabwidg->setDocumentMode(false);
        astabwidg->setTabsClosable(false);
        astabwidg->setMovable(false);
        modt = new QWidget();
        modt->setObjectName(QStringLiteral("modt"));
        verticalLayout_6 = new QVBoxLayout(modt);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        modtablayout = new QVBoxLayout();
        modtablayout->setSpacing(6);
        modtablayout->setObjectName(QStringLiteral("modtablayout"));
        modtabv = new QTableView(modt);
        modtabv->setObjectName(QStringLiteral("modtabv"));
        modtabv->setLayoutDirection(Qt::LeftToRight);
        modtabv->setAutoFillBackground(false);
        modtabv->setSizeAdjustPolicy(QAbstractScrollArea::AdjustIgnored);
        modtabv->setEditTriggers(QAbstractItemView::DoubleClicked);
        modtabv->setAlternatingRowColors(true);
        modtabv->setSelectionBehavior(QAbstractItemView::SelectRows);
        modtabv->setVerticalScrollMode(QAbstractItemView::ScrollPerItem);
        modtabv->setShowGrid(true);
        modtabv->setGridStyle(Qt::SolidLine);
        modtabv->setSortingEnabled(true);
        modtabv->horizontalHeader()->setCascadingSectionResizes(true);
        modtabv->horizontalHeader()->setStretchLastSection(false);
        modtabv->verticalHeader()->setCascadingSectionResizes(true);

        modtablayout->addWidget(modtabv);


        verticalLayout_6->addLayout(modtablayout);

        astabwidg->addTab(modt, QString());
        rigt = new QWidget();
        rigt->setObjectName(QStringLiteral("rigt"));
        verticalLayout_8 = new QVBoxLayout(rigt);
        verticalLayout_8->setSpacing(6);
        verticalLayout_8->setContentsMargins(11, 11, 11, 11);
        verticalLayout_8->setObjectName(QStringLiteral("verticalLayout_8"));
        rigtabayout = new QVBoxLayout();
        rigtabayout->setSpacing(6);
        rigtabayout->setObjectName(QStringLiteral("rigtabayout"));
        rigtabv = new QTableView(rigt);
        rigtabv->setObjectName(QStringLiteral("rigtabv"));
        rigtabv->setEditTriggers(QAbstractItemView::DoubleClicked);
        rigtabv->setAlternatingRowColors(true);
        rigtabv->setSelectionBehavior(QAbstractItemView::SelectRows);
        rigtabv->horizontalHeader()->setCascadingSectionResizes(true);
        rigtabv->verticalHeader()->setCascadingSectionResizes(true);

        rigtabayout->addWidget(rigtabv);


        verticalLayout_8->addLayout(rigtabayout);

        astabwidg->addTab(rigt, QString());

        astabLayout->addWidget(astabwidg);

        asprevLayout = new QVBoxLayout();
        asprevLayout->setSpacing(4);
        asprevLayout->setObjectName(QStringLiteral("asprevLayout"));
        asprevLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        asprevLayout->setContentsMargins(2, 2, 2, 2);
        asprevlab = new QLabel(asPage);
        asprevlab->setObjectName(QStringLiteral("asprevlab"));
        asprevlab->setMinimumSize(QSize(164, 105));
        asprevlab->setMaximumSize(QSize(164, 105));
        asprevlab->setLayoutDirection(Qt::LeftToRight);
        asprevlab->setFrameShape(QFrame::Box);
        asprevlab->setPixmap(QPixmap(QString::fromUtf8("S:/intelture/Pipeline/noPreview.png")));
        asprevlab->setScaledContents(true);
        asprevlab->setAlignment(Qt::AlignCenter);

        asprevLayout->addWidget(asprevlab);

        asprolab = new QLabel(asPage);
        asprolab->setObjectName(QStringLiteral("asprolab"));
        asprolab->setMinimumSize(QSize(164, 105));
        asprolab->setMaximumSize(QSize(164, 105));
        asprolab->setPixmap(QPixmap(QString::fromUtf8("S:/intelture/Pipeline/noPreview.png")));
        asprolab->setScaledContents(true);
        asprolab->setAlignment(Qt::AlignCenter);

        asprevLayout->addWidget(asprolab);


        astabLayout->addLayout(asprevLayout);


        horizontalLayout->addLayout(astabLayout);

        stackedWidget->addWidget(asPage);
        shPage = new QWidget();
        shPage->setObjectName(QStringLiteral("shPage"));
        horizontalLayout_3 = new QHBoxLayout(shPage);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        shtabLayout = new QHBoxLayout();
        shtabLayout->setSpacing(6);
        shtabLayout->setObjectName(QStringLiteral("shtabLayout"));
        shtabwidg = new QTabWidget(shPage);
        shtabwidg->setObjectName(QStringLiteral("shtabwidg"));
        shtabwidg->setFont(font1);
        prevt = new QWidget();
        prevt->setObjectName(QStringLiteral("prevt"));
        verticalLayout_9 = new QVBoxLayout(prevt);
        verticalLayout_9->setSpacing(6);
        verticalLayout_9->setContentsMargins(11, 11, 11, 11);
        verticalLayout_9->setObjectName(QStringLiteral("verticalLayout_9"));
        prevtabLayout = new QVBoxLayout();
        prevtabLayout->setSpacing(6);
        prevtabLayout->setObjectName(QStringLiteral("prevtabLayout"));
        prevtabv = new QTableView(prevt);
        prevtabv->setObjectName(QStringLiteral("prevtabv"));
        prevtabv->setEditTriggers(QAbstractItemView::DoubleClicked);
        prevtabv->setAlternatingRowColors(true);
        prevtabv->setSelectionBehavior(QAbstractItemView::SelectRows);
        prevtabv->setSortingEnabled(true);
        prevtabv->horizontalHeader()->setCascadingSectionResizes(true);
        prevtabv->verticalHeader()->setCascadingSectionResizes(true);

        prevtabLayout->addWidget(prevtabv);


        verticalLayout_9->addLayout(prevtabLayout);

        shtabwidg->addTab(prevt, QString());
        blkt = new QWidget();
        blkt->setObjectName(QStringLiteral("blkt"));
        verticalLayout_10 = new QVBoxLayout(blkt);
        verticalLayout_10->setSpacing(6);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QStringLiteral("verticalLayout_10"));
        blktabLayout = new QVBoxLayout();
        blktabLayout->setSpacing(6);
        blktabLayout->setObjectName(QStringLiteral("blktabLayout"));
        blktabv = new QTableView(blkt);
        blktabv->setObjectName(QStringLiteral("blktabv"));
        blktabv->setEditTriggers(QAbstractItemView::DoubleClicked);
        blktabv->setAlternatingRowColors(true);
        blktabv->setSelectionBehavior(QAbstractItemView::SelectRows);
        blktabv->setSortingEnabled(true);
        blktabv->horizontalHeader()->setCascadingSectionResizes(true);
        blktabv->verticalHeader()->setCascadingSectionResizes(true);

        blktabLayout->addWidget(blktabv);


        verticalLayout_10->addLayout(blktabLayout);

        shtabwidg->addTab(blkt, QString());
        animt = new QWidget();
        animt->setObjectName(QStringLiteral("animt"));
        verticalLayout_11 = new QVBoxLayout(animt);
        verticalLayout_11->setSpacing(6);
        verticalLayout_11->setContentsMargins(11, 11, 11, 11);
        verticalLayout_11->setObjectName(QStringLiteral("verticalLayout_11"));
        anitabLayout = new QVBoxLayout();
        anitabLayout->setSpacing(6);
        anitabLayout->setObjectName(QStringLiteral("anitabLayout"));
        anitabv = new QTableView(animt);
        anitabv->setObjectName(QStringLiteral("anitabv"));
        anitabv->setEditTriggers(QAbstractItemView::DoubleClicked);
        anitabv->setAlternatingRowColors(true);
        anitabv->setSelectionBehavior(QAbstractItemView::SelectRows);
        anitabv->setSortingEnabled(true);
        anitabv->horizontalHeader()->setCascadingSectionResizes(true);
        anitabv->verticalHeader()->setCascadingSectionResizes(true);

        anitabLayout->addWidget(anitabv);


        verticalLayout_11->addLayout(anitabLayout);

        shtabwidg->addTab(animt, QString());
        light = new QWidget();
        light->setObjectName(QStringLiteral("light"));
        verticalLayout_12 = new QVBoxLayout(light);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QStringLiteral("verticalLayout_12"));
        ligtabLayout = new QVBoxLayout();
        ligtabLayout->setSpacing(6);
        ligtabLayout->setObjectName(QStringLiteral("ligtabLayout"));
        lighttabv = new QTableView(light);
        lighttabv->setObjectName(QStringLiteral("lighttabv"));
        lighttabv->setEditTriggers(QAbstractItemView::DoubleClicked);
        lighttabv->setAlternatingRowColors(true);
        lighttabv->setSelectionBehavior(QAbstractItemView::SelectRows);
        lighttabv->setSortingEnabled(true);
        lighttabv->horizontalHeader()->setCascadingSectionResizes(true);
        lighttabv->verticalHeader()->setCascadingSectionResizes(true);

        ligtabLayout->addWidget(lighttabv);


        verticalLayout_12->addLayout(ligtabLayout);

        shtabwidg->addTab(light, QString());

        shtabLayout->addWidget(shtabwidg);

        shprevLayout = new QVBoxLayout();
        shprevLayout->setSpacing(6);
        shprevLayout->setObjectName(QStringLiteral("shprevLayout"));
        shprevlab = new QLabel(shPage);
        shprevlab->setObjectName(QStringLiteral("shprevlab"));
        shprevlab->setMinimumSize(QSize(164, 105));
        shprevlab->setMaximumSize(QSize(164, 105));
        shprevlab->setFrameShape(QFrame::Box);
        shprevlab->setPixmap(QPixmap(QString::fromUtf8("S:/intelture/Pipeline/noPreview.png")));
        shprevlab->setAlignment(Qt::AlignCenter);

        shprevLayout->addWidget(shprevlab);

        shprolab = new QLabel(shPage);
        shprolab->setObjectName(QStringLiteral("shprolab"));
        shprolab->setMinimumSize(QSize(164, 105));
        shprolab->setMaximumSize(QSize(164, 105));
        shprolab->setPixmap(QPixmap(QString::fromUtf8("S:/intelture/Pipeline/noPreview.png")));
        shprolab->setAlignment(Qt::AlignCenter);

        shprevLayout->addWidget(shprolab);


        shtabLayout->addLayout(shprevLayout);


        horizontalLayout_3->addLayout(shtabLayout);

        stackedWidget->addWidget(shPage);

        verticalLayout_2->addWidget(stackedWidget);


        verticalLayout->addWidget(stckLayout_2);

        curstate = new QLabel(assign_wiz);
        curstate->setObjectName(QStringLiteral("curstate"));
        curstate->setMinimumSize(QSize(0, 40));
        QFont font3;
        font3.setFamily(QStringLiteral("Trebuchet MS"));
        font3.setPointSize(12);
        font3.setBold(true);
        font3.setItalic(false);
        font3.setWeight(75);
        curstate->setFont(font3);
        curstate->setStyleSheet(QStringLiteral("color: rgb(255, 255, 255);"));

        verticalLayout->addWidget(curstate);

        QWidget::setTabOrder(asbut, shbut);
        QWidget::setTabOrder(shbut, procombo);
        QWidget::setTabOrder(procombo, epcombo);
        QWidget::setTabOrder(epcombo, astabwidg);
        QWidget::setTabOrder(astabwidg, modtabv);
        QWidget::setTabOrder(modtabv, rigtabv);
        QWidget::setTabOrder(rigtabv, shtabwidg);
        QWidget::setTabOrder(shtabwidg, prevtabv);
        QWidget::setTabOrder(prevtabv, blktabv);
        QWidget::setTabOrder(blktabv, anitabv);
        QWidget::setTabOrder(anitabv, lighttabv);
        QWidget::setTabOrder(lighttabv, procombo);
        QWidget::setTabOrder(procombo, epcombo);

        retranslateUi(assign_wiz);

        stackedWidget->setCurrentIndex(0);
        astabwidg->setCurrentIndex(0);
        shtabwidg->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(assign_wiz);
    } // setupUi

    void retranslateUi(QWidget *assign_wiz)
    {
        assign_wiz->setWindowTitle(QApplication::translate("assign_wiz", "assign_wiz", 0));
        procombo->clear();
        procombo->insertItems(0, QStringList()
         << QApplication::translate("assign_wiz", "Jinnrise", 0)
         << QApplication::translate("assign_wiz", "Megabear", 0)
         << QApplication::translate("assign_wiz", "Maskmaster2", 0)
        );
        datelab->setText(QApplication::translate("assign_wiz", "19/09/2014", 0));
        asbut->setText(QApplication::translate("assign_wiz", "Assets", 0));
        shbut->setText(QApplication::translate("assign_wiz", "Shots", 0));
        astabwidg->setTabText(astabwidg->indexOf(modt), QApplication::translate("assign_wiz", "Model", 0));
        astabwidg->setTabText(astabwidg->indexOf(rigt), QApplication::translate("assign_wiz", "Rig", 0));
        asprevlab->setText(QString());
        asprolab->setText(QString());
        shtabwidg->setTabText(shtabwidg->indexOf(prevt), QApplication::translate("assign_wiz", "Previs", 0));
        shtabwidg->setTabText(shtabwidg->indexOf(blkt), QApplication::translate("assign_wiz", "Blocking", 0));
        shtabwidg->setTabText(shtabwidg->indexOf(animt), QApplication::translate("assign_wiz", "Animation", 0));
        shtabwidg->setTabText(shtabwidg->indexOf(light), QApplication::translate("assign_wiz", "Lighting", 0));
        shprevlab->setText(QString());
        shprolab->setText(QString());
        curstate->setText(QApplication::translate("assign_wiz", "Jinnrise / EP01 / Assets / Characters", 0));
    } // retranslateUi

};

namespace Ui {
    class assign_wiz: public Ui_assign_wiz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ASSIGN_WIZ_H
