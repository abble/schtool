#include "apr_wiz.h"
#include "ui_apr_wiz.h"

apr_Wiz::apr_Wiz(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::apr_Wiz)
{
    ui->setupUi(this);
}

apr_Wiz::~apr_Wiz()
{
    delete ui;
}
