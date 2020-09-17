#ifndef TEST3_H
#define TEST3_H

#include <QQuickItem>

class ItemBase3 : public QQuickItem
{
    Q_OBJECT

public:
    ItemBase3(QQuickItem *parent = 0);
    virtual ~ItemBase3();

public slots:
    void onDestroyedFromItemBase3(QObject *object);
};

class MyItem3 : public ItemBase3
{
    Q_OBJECT

public:
    MyItem3(QString name, QQuickItem *parent = 0);
    ~MyItem3();

public slots:
    void onDestroyedFromMyItem3(QObject *object);
};

class ItemHolder : public QQuickItem
{
    Q_OBJECT

public:
    ItemHolder(QQuickItem *parent = 0);
    ~ItemHolder();

    void setItem3(MyItem3 *item);
    void setItem31(MyItem3 *item);
    void setBrother(ItemHolder *item);

public slots:
    void onDestroyedFromItemHolder(QObject *object);

private:
    MyItem3 *m_pChild;
    MyItem3 *m_pMyItem3;
    MyItem3 *m_pMyItem31;
    ItemHolder *m_pBrother;
};

class ItemTest3 : public QQuickItem
{
    Q_OBJECT

public:
    ItemTest3(QQuickItem *parent = 0);
    ~ItemTest3();

public slots:
    void doCreate();
    void doDestroy();
    void doCheck();

public slots:
    void onDestroyedFromItemTest3(QObject *object);

private:
    bool m_bCreated;
    ItemHolder *m_pItemHolder;
    ItemHolder *m_pItemHolder2;
    MyItem3 *m_pMyItem3;
    MyItem3 *m_pMyItem31;
};

#endif // TEST3_H
