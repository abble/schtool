#ifndef ART_WIZ_H
#define ART_WIZ_H

#include <QWidget>

namespace Ui {
class art_Wiz;
}

class art_Wiz : public QWidget
{
    Q_OBJECT

public:
    explicit art_Wiz(QWidget *parent = 0);
    ~art_Wiz();

private:
    Ui::art_Wiz *ui;
};

#endif // ART_WIZ_H
