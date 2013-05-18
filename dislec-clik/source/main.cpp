#include <QApplication>
#include <QTextCodec>
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));

    Controller c;
    c.show();
    return a.exec();
}
