#include "ctkt.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CTKT w;
    w.show();
    return a.exec();
}
