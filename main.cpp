#include "mainwindow.h"
#include <QApplication>

#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.initialize();
    qDebug() << "App path: " << a.applicationDirPath();
    w.show();




    return a.exec();
}



//TODO: check if program compiles with ö, ä, ß, i.e. german language
