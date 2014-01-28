#include "snowloadcountmw.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SnowLoadCountmw slcmw;
    
    slcmw.showExpanded();
    return a.exec();
}
