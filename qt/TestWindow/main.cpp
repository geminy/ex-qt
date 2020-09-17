#include <QGuiApplication>
#include <QQuickWindow>
#include <QQuickView>
#include <QQuickItem>
#include <QtQml>
#include <QDebug>

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQuickWindow *window = new QQuickWindow;
    window->setTitle("evo");
    window->setGeometry(0, 0, 360, 360);
    window->show();
    qDebug() << window->x() << window->y() << window->width() << window->height();
    qDebug() << window->contentItem()->x() << window->contentItem()->y() << window->contentItem()->width() << window->contentItem()->height();

    QQmlEngine engine;

    QQmlComponent screen(&engine, QUrl("qrc:///main.qml"));
    QQuickItem *item = qobject_cast<QQuickItem*>(screen.create());
    item->setParentItem(window->contentItem());
    item->setVisible(true);

    QQuickItem *root = new QQuickItem;
    root->setX(window->x());
    root->setY(window->y());
    root->setWidth(window->width());
    root->setHeight(window->height());
    root->setParentItem(window->contentItem());
    root->setVisible(true);

    QQuickItem *main = new QQuickItem;
    main->setX(root->x());
    main->setY(root->y());
    main->setWidth(root->width());
    main->setHeight(root->height());
    main->setParentItem(root);
    main->setVisible(true);

    QQmlComponent screen2(&engine, QUrl("qrc:///main2.qml"));
    QQuickItem *item2 = qobject_cast<QQuickItem*>(screen2.create());
    item2->setX(100);
    item2->setY(100);
    item2->setParentItem(main);
    item2->setVisible(true);

    return app.exec();
}
