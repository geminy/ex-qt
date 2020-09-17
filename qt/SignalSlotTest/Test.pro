TEMPLATE = app

QT += qml quick
CONFIG += c++11

SOURCES += main.cpp \
    test.cpp \
    test2.cpp \
    test3.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    test.h \
    test2.h \
    test3.h

DISTFILES +=
