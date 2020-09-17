#include "test.h"
#include "test2.h"
#include "test3.h"

#include <QGuiApplication>
#include <QtQml>
#include <QQuickView>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<MyItem>("test", 1, 0, "MyItem");
    qmlRegisterType<ItemTest>("test", 1, 0, "ItemTest");
    qmlRegisterType<ItemTest3>("test", 1, 0, "ItemTest3");

    QQuickView *view = new QQuickView;
//    view->setSource(QUrl(QStringLiteral("qrc:///main.qml")));
//    view->setSource(QUrl(QStringLiteral("qrc:///main2.qml")));
    view->setSource(QUrl(QStringLiteral("qrc:///main3.qml")));

    view->show();

    return app.exec();
}
