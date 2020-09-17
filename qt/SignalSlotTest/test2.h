#ifndef TEST2_H
#define TEST2_H

#include <QQuickItem>

class ItemBase2 : public QQuickItem
{
    Q_OBJECT

public:
    ItemBase2();
    virtual ~ItemBase2();

    virtual void function();
//    virtual void function() = 0; // crash

signals:
    void signalFromItemBase();
};

class ItemBase21
{
public:
    ItemBase21();
    virtual ~ItemBase21();

    virtual void function21();
};

class MyItem2 : public ItemBase2, public ItemBase21
{
    Q_OBJECT

public:
    MyItem2();
    ~MyItem2();

    void function();
    void function21();
    void function2();

signals:
    void signalFromMyItem();

public:
    QQuickItem *m_pItem;
};

class ItemTest : public QQuickItem
{
    Q_OBJECT

public:
    ItemTest();
    ~ItemTest();

public slots:
    void onDestroyedFromQt(QObject *object);
    void onTriggeredFromItemBase();
    void onTriggeredFromMyItem();

    void doCreate();
    void doDestroy();

private:
    MyItem2 *m_pMyItem;
    QQuickItem *m_pItem;
};

#endif // TEST2_H
