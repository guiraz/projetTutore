#include "mainwindow.h"
#include <qtextcodec.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("utf-8"));
    MainWindow w;
    w.setWindowState(Qt::WindowFullScreen);
    w.show();
    return a.exec();
}
