#include <QtGui/QApplication>
#include "ged.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ged w;
    w.show();

    return a.exec();
}
