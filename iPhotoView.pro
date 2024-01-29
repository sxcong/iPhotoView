#-------------------------------------------------
#
# Project created by QtCreator 2024-01-15T14:01:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = iPhotoView
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

SOURCES += \
        main.cpp \
        mainwidget.cpp \
    imageutils.cpp \
    global.cpp \
    PhotoMetaData.cpp \
    Photo.cpp \
    PhotoDir.cpp \
    PrefetchCache.cpp \
    PhotoView.cpp \
    BorderPanel.cpp \
    Canvas.cpp \
    ExifBorderPanel.cpp \
    Panner.cpp \
    SensitiveBorder.cpp \
    TextBorderPanel.cpp \
    GraphicsItemPosAnimation.cpp \
    qvaboutdialog.cpp \
    qvaboutdialog.cpp \
    actionmanager.cpp \
    openwith.cpp \
    qvwelcomedialog.cpp \
    shortcutmanager.cpp \
    settingsmanager.cpp \
    qvwin32functions.cpp \
    imagefilemanager.cpp \
    toolbarwidget.cpp \
    exifinfo.cpp \
    TJPEGWrapper.cpp

HEADERS += \
        mainwidget.h \
    imageutils.h \
    global.h \
    PhotoMetaData.h \
    Photo.h \
    PhotoDir.h \
    PrefetchCache.h \
    PhotoView.h \
    BorderPanel.h \
    Canvas.h \
    ExifBorderPanel.h \
    Panner.h \
    SensitiveBorder.h \
    TextBorderPanel.h \
    GraphicsItemPosAnimation.h \
    qvaboutdialog.h \
    qvaboutdialog.h \
    actionmanager.h \
    openwith.h \
    qvwelcomedialog.h \
    shortcutmanager.h \
    settingsmanager.h \
    qvwin32functions.h \
    imagefilemanager.h \
    toolbarwidget.h \
    exifinfo.h \
    TJPEGWrapper.h

FORMS += \
        mainwidget.ui \
    qvaboutdialog.ui \
    qvopenwithdialog.ui \
    qvwelcomedialog.ui \
    toolbarwidget.ui

CONFIG(release, debug|release){
    TARGET = iPhotoView
    DESTDIR=$$PWD/./bin/Release
    LIBS += -L$$PWD/./lib/ -llibx265 -lturbojpeg -llibwebp -lheif -lde265 -lFreeImage -lFreeImagePlus -lexiv2
    LIBS += -lshell32 -luser32 -lole32 -lshlwapi -lgdi32
      #TRANSLATIONS += $$PWD/../Bin/Release/translations/das_qt_cn.ts
}

CONFIG(debug, debug|release){
    TARGET = iPhotoView_d
    DESTDIR=$$PWD/./bin/Debug
    LIBS += -L$$PWD/./lib  -llibx265 -lturbojpeg -llibwebp -lheif -lde265 -lFreeImage -lFreeImagePlus -lexiv2
LIBS += -lshell32 -luser32 -lole32 -lshlwapi -lgdi32
    #TRANSLATIONS += $$PWD/../Bin/Debug/translations/das_qt_cn.ts
}

msvc {
    QMAKE_CFLAGS += /utf-8
    QMAKE_CXXFLAGS += /utf-8
}

INCLUDEPATH += $$PWD/include/
INCLUDEPATH += $$PWD/include/wtl
INCLUDEPATH += $$PWD/include/libheif

RESOURCES += \
    resources/resources.qrc
