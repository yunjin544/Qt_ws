#include "mainwindow.h"
#include <QApplication>
#include "Shared_Memory.h"

#define KEY_NUM 1234
int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    MainWindow w;

    w.show();
    return a.exec();
}
