#ifndef APR_WIZ_H
#define APR_WIZ_H

#include <QWidget>

namespace Ui {
class apr_Wiz;
}

class apr_Wiz : public QWidget
{
    Q_OBJECT

public:
    explicit apr_Wiz(QWidget *parent = 0);
    ~apr_Wiz();

private:
    Ui::apr_Wiz *ui;
};

#endif // APR_WIZ_H
