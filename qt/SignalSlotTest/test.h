#ifndef TEST_H
#define TEST_H

#include <QQuickItem>

class ItemBase : public QQuickItem
{
    Q_OBJECT

public:
    ItemBase();
    virtual ~ItemBase();

signals:
//    void signalTriggered();
};

class MyItem : public ItemBase
{
    Q_OBJECT

public:
    MyItem();
    ~MyItem();

signals:
    void signalTriggered();

public slots:
    void onVisibleChanged();
    void onEnableChanged();
    void onSignalTriggered();
    void onMouseClicked();
    void onMouseClicked2();
};

#endif // TEST_H
