#include "assign_wiz.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    assign_wiz w;
    w.show();

    return a.exec();
}
