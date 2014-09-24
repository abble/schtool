#include "art_wiz.h"
#include "ui_art_wiz.h"

art_Wiz::art_Wiz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::art_Wiz)
{
    ui->setupUi(this);
}

art_Wiz::~art_Wiz()
{
    delete ui;
}
