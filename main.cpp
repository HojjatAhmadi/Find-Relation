#include "findrel.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FindRel w;
    w.show();
    return a.exec();
}
