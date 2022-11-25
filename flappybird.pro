QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Score.cpp \
    birditem.cpp \
    clickokay.cpp \
    main.cpp \
    mainwindow.cpp \
    pillaritem.cpp \
    playgame.cpp \
    scene.cpp \
    widget.cpp

HEADERS += \
    Score.h \
    birditem.h \
    clickokay.h \
    mainwindow.h \
    pillaritem.h \
    playgame.h \
    scene.h \
    widget.h

FORMS += \
    clickokay.ui \
    mainwindow.ui \
    playgame.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resouce.qrc
