TEMPLATE = app

QT += qml quick qml-private quick-private core-private gui-private

SOURCES += main.cpp

RESOURCES += qml.qrc \
    res/bmp/bmpimages.qrc \
    res/png/pngimages.qrc \
    res/save/saveimages.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)
