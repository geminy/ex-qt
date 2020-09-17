//#include <QGuiApplication>
//#include <QQmlApplicationEngine>

//int main(int argc, char *argv[])
//{
//    QGuiApplication app(argc, argv);

//    QQmlApplicationEngine engine;
//    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

//    return app.exec();
//}

#include <QApplication>
#include <QtQml>
#include <QQuickView>
#include "demo.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    qmlRegisterType<Demo>("aidear.com", 1, 0, "Demo");

    QQuickView view;
    view.setSource(QUrl(QStringLiteral("qrc:/propbindl.qml")));
    view.show();

    return app.exec();
}
