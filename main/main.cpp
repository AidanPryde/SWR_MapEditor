#include "main\mainwindow.h"
#include "main\global.h"

#include <QApplication>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;

    w.show();

    return a.exec();
}
