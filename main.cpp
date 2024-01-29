#include "mainwidget.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setOrganizationName("iPhotoView");
    QCoreApplication::setApplicationName("iPhotoView");
    QCoreApplication::setApplicationVersion(QString::number(0.1));
    QApplication a(argc, argv);

    MainWidget w;
    w.show();

    return a.exec();
}
