#include "mainwindow.h"
#include <QApplication>             // handles all action related to window
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);         //creates app objcet
    MainWindow w;                       // creates main app object
    QDesktopWidget desktop;
    w.resize(desktop.availableGeometry().size() * 0.7);
    w.show();

    return a.exec();                    //loops code
}
