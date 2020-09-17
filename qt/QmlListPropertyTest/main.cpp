#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQml>
#include <mybutton.h>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<ButtonText>("test", 1, 0, "ButtonText");
    qmlRegisterType<MyButton>("test", 1, 0, "MyButton");
    qmlRegisterType<MyItem>("test", 1, 0, "MyItem");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
