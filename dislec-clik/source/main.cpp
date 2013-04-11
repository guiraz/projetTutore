#include "controller.h"
#include <qtextcodec.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));

    Controller c;
    c.show();

    return a.exec();
}
