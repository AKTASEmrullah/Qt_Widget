#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication Application(argc, argv);
    MainWindow w;
    w.show();
    return Application.exec();
}
