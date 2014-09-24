#include "art_wiz.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    art_Wiz w;
    w.show();

    return a.exec();
}
