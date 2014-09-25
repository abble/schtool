/********************************************************************************
** Form generated from reading UI file 'apr_wiz.ui'
**
** Created by: Qt User Interface Compiler version 5.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_APR_WIZ_H
#define UI_APR_WIZ_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableView>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_apr_Wiz
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
    QFrame *frame_4;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_4;
    QLabel *label_3;
    QLineEdit *lineEdit;
    QFrame *frame;
    QHBoxLayout *horizontalLayout_7;
    QTextEdit *textEdit_2;
    QLabel *label;
    QFrame *frame_2;
    QHBoxLayout *horizontalLayout_6;
    QTextEdit *textEdit;
    QLabel *label_2;
    QFrame *frame_3;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QFrame *prevLayout;
    QVBoxLayout *verticalLayout_2;
    QLabel *prevlab;
    QLabel *prolab;
    QLabel *curstate;

    void setupUi(QWidget *apr_Wiz)
    {
        if (apr_Wiz->objectName().isEmpty())
            apr_Wiz->setObjectName(QStringLiteral("apr_Wiz"));
        apr_Wiz->resize(980, 400);
        verticalLayout = new QVBoxLayout(apr_Wiz);
        verticalLayout->setSpacing(2);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(2, 2, 2, 2);
        epdateLayout = new QFrame(apr_Wiz);
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
        font.setFamily(QStringLiteral("Comic Sans MS"));
        font.setPointSize(12);
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
        font1.setFamily(QStringLiteral("Comic Sans MS"));
        font1.setPointSize(10);
        font1.setBold(true);
        font1.setWeight(75);
        datelab->setFont(font1);
        datelab->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(datelab);


        verticalLayout->addWidget(epdateLayout);

        mainLayout = new QFrame(apr_Wiz);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        mainLayout->setStyleSheet(QStringLiteral("background-color: rgb(213, 213, 213);"));
        mainLayout->setFrameShape(QFrame::StyledPanel);
        mainLayout->setFrameShadow(QFrame::Raised);
        horizontalLayout_2 = new QHBoxLayout(mainLayout);
        horizontalLayout_2->setSpacing(2);
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
        detLayout->setMinimumSize(QSize(420, 0));
        detLayout->setMaximumSize(QSize(420, 16777215));
        detLayout->setFrameShape(QFrame::StyledPanel);
        detLayout->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(detLayout);
        verticalLayout_3->setSpacing(2);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(2, 2, 2, 2);
        frame_4 = new QFrame(detLayout);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setMinimumSize(QSize(0, 40));
        frame_4->setMaximumSize(QSize(16777215, 60));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        horizontalLayout_3 = new QHBoxLayout(frame_4);
        horizontalLayout_3->setSpacing(2);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(2, 2, 2, 2);
        label_4 = new QLabel(frame_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(200, 30));
        label_4->setMaximumSize(QSize(200, 30));
        label_4->setAlignment(Qt::AlignCenter);

        horizontalLayout_3->addWidget(label_4);

        label_3 = new QLabel(frame_4);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(0, 30));
        label_3->setMaximumSize(QSize(16777215, 30));
        label_3->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(label_3);

        lineEdit = new QLineEdit(frame_4);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setMinimumSize(QSize(100, 30));
        lineEdit->setMaximumSize(QSize(100, 16777215));

        horizontalLayout_3->addWidget(lineEdit);


        verticalLayout_3->addWidget(frame_4);

        frame = new QFrame(detLayout);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setMinimumSize(QSize(0, 100));
        frame->setMaximumSize(QSize(16777215, 16777215));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        horizontalLayout_7 = new QHBoxLayout(frame);
        horizontalLayout_7->setSpacing(2);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(2, 2, 2, 2);
        textEdit_2 = new QTextEdit(frame);
        textEdit_2->setObjectName(QStringLiteral("textEdit_2"));

        horizontalLayout_7->addWidget(textEdit_2);


        verticalLayout_3->addWidget(frame);

        label = new QLabel(detLayout);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(16777215, 20));
        label->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label);

        frame_2 = new QFrame(detLayout);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setMaximumSize(QSize(16777215, 16777215));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        horizontalLayout_6 = new QHBoxLayout(frame_2);
        horizontalLayout_6->setSpacing(2);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(2, 2, 2, 2);
        textEdit = new QTextEdit(frame_2);
        textEdit->setObjectName(QStringLiteral("textEdit"));

        horizontalLayout_6->addWidget(textEdit);


        verticalLayout_3->addWidget(frame_2);

        label_2 = new QLabel(detLayout);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(16777215, 20));
        label_2->setAlignment(Qt::AlignCenter);

        verticalLayout_3->addWidget(label_2);

        frame_3 = new QFrame(detLayout);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setMaximumSize(QSize(16777215, 50));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        horizontalLayout_5 = new QHBoxLayout(frame_3);
        horizontalLayout_5->setSpacing(2);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(2, 2, 2, 2);
        pushButton_3 = new QPushButton(frame_3);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setMinimumSize(QSize(0, 40));

        horizontalLayout_5->addWidget(pushButton_3);

        pushButton = new QPushButton(frame_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setMinimumSize(QSize(0, 40));

        horizontalLayout_5->addWidget(pushButton);


        verticalLayout_3->addWidget(frame_3);


        horizontalLayout_4->addWidget(detLayout);


        horizontalLayout_2->addWidget(subLayout);

        prevLayout = new QFrame(mainLayout);
        prevLayout->setObjectName(QStringLiteral("prevLayout"));
        prevLayout->setFrameShape(QFrame::StyledPanel);
        prevLayout->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(prevLayout);
        verticalLayout_2->setSpacing(4);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(2, 2, 2, 2);
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

        curstate = new QLabel(apr_Wiz);
        curstate->setObjectName(QStringLiteral("curstate"));
        curstate->setMinimumSize(QSize(0, 40));
        curstate->setMaximumSize(QSize(16777215, 40));
        QFont font2;
        font2.setFamily(QStringLiteral("Comic Sans MS"));
        font2.setPointSize(14);
        curstate->setFont(font2);
        curstate->setStyleSheet(QStringLiteral("background-color: rgb(80, 80, 80);"));

        verticalLayout->addWidget(curstate);


        retranslateUi(apr_Wiz);

        QMetaObject::connectSlotsByName(apr_Wiz);
    } // setupUi

    void retranslateUi(QWidget *apr_Wiz)
    {
        apr_Wiz->setWindowTitle(QApplication::translate("apr_Wiz", "apr_Wiz", 0));
        procombo->clear();
        procombo->insertItems(0, QStringList()
         << QApplication::translate("apr_Wiz", "Jinnrise", 0)
         << QApplication::translate("apr_Wiz", "Megabear", 0)
         << QApplication::translate("apr_Wiz", "Maskmaster2", 0)
        );
        datelab->setText(QApplication::translate("apr_Wiz", "24/9/2014", 0));
        label_4->setText(QApplication::translate("apr_Wiz", "TextLabel", 0));
        label_3->setText(QApplication::translate("apr_Wiz", "TextLabel", 0));
        label->setText(QApplication::translate("apr_Wiz", "Lead Comments", 0));
        label_2->setText(QApplication::translate("apr_Wiz", "Director Comments", 0));
        pushButton_3->setText(QApplication::translate("apr_Wiz", "Approve", 0));
        pushButton->setText(QApplication::translate("apr_Wiz", "Rework", 0));
        prevlab->setText(QString());
        prolab->setText(QString());
        curstate->setText(QApplication::translate("apr_Wiz", "Jinnrise", 0));
    } // retranslateUi

};

namespace Ui {
    class apr_Wiz: public Ui_apr_Wiz {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_APR_WIZ_H
