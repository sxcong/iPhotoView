#include "mainwidget.h"
#include <QApplication>
#include "PhotoView.h"
#include "PhotoDir.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QCoreApplication::setOrganizationName("qView");
    QCoreApplication::setApplicationName("qView");
    QCoreApplication::setApplicationVersion(QString::number(0.1));
    QApplication a(argc, argv);
    MainWidget w;
    w.show();

    //QString path = "C:/Users/Tiger/Pictures";
    //PhotoDir dir( path );
    //PhotoView viewer( &dir );

    //PhotoView viewer;
    //viewer.setWindowState( viewer.windowState() | Qt::WindowFullScreen );
    //viewer.show();
    return a.exec();
}
