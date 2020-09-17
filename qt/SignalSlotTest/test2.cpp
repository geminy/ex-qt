#include "test2.h"

#include <QDebug>

#include <cstring>
#include <cstdlib>

ItemBase2::ItemBase2()
{
    setObjectName(QString("ItemBase"));
    qDebug() << __PRETTY_FUNCTION__ << "this:" << this;
}

ItemBase2::~ItemBase2()
{
    qDebug() << __PRETTY_FUNCTION__ << "this:" << this;

    emit signalFromItemBase();
}

void ItemBase2::function()
{
    qDebug() << __PRETTY_FUNCTION__ << "this:" << this;
}

ItemBase21::ItemBase21()
{
    qDebug() << __PRETTY_FUNCTION__ << "this:" << this;
}

ItemBase21::~ItemBase21()
{
    qDebug() << __PRETTY_FUNCTION__ << "this:" << this;
}

void ItemBase21::function21()
{
    qDebug() << __PRETTY_FUNCTION__ << "this:" << this;
}

MyItem2::MyItem2()
    : m_pItem(new QQuickItem)
{
    this->setObjectName(QString("MyItem"));
    m_pItem->setObjectName(QString("QQuickItem"));
    qDebug() << __PRETTY_FUNCTION__ << "this:" << this;
}

MyItem2::~MyItem2()
{
    qDebug() << __PRETTY_FUNCTION__ << "this:" << this;

    emit signalFromMyItem();

    if (m_pItem) {
        delete m_pItem;
        m_pItem = NULL;
    }
}

void MyItem2::function()
{
    qDebug() << __PRETTY_FUNCTION__ << "this:" << this;
}

void MyItem2::function21()
{
    qDebug() << __PRETTY_FUNCTION__ << "this:" << this;
}

void MyItem2::function2()
{
    qDebug() << __PRETTY_FUNCTION__ << "this:" << this;
}

ItemTest::ItemTest()
    : m_pMyItem(NULL)
    , m_pItem(new QQuickItem)
{
    qDebug() << __PRETTY_FUNCTION__ << "MyItem:" << m_pMyItem;

    if (m_pMyItem) {
        m_pMyItem->function();
        m_pMyItem->function2();
        m_pMyItem->function21();
    }
}

ItemTest::~ItemTest()
{
    qDebug() << __PRETTY_FUNCTION__ << "MyItem:" << m_pMyItem;
    if (m_pMyItem) {
        m_pMyItem->function();
        m_pMyItem->function2();
        m_pMyItem->function21();
    }

    disconnect(m_pMyItem, 0, this, 0);
}

void ItemTest::onDestroyedFromQt(QObject *object)
{
    qDebug() << __PRETTY_FUNCTION__ << "object:" << object;
    qDebug() << __PRETTY_FUNCTION__ << "MyItem:" << m_pMyItem;
    if (object) {
        MyItem2 *item = qobject_cast<MyItem2*>(object);
        qDebug() << __PRETTY_FUNCTION__ << "qobject_cast:" << item;
        if (item) {
            item->function();
            item->function2();
            item->function21();
            qDebug() << __PRETTY_FUNCTION__ << item->m_pItem;
        }

        MyItem2 *item2 = static_cast<MyItem2*>(object);
        qDebug() << __PRETTY_FUNCTION__ << "static_cast:" << item2;
        if (item2) {
            item2->function();
            item2->function2();
//            item2->function21();
            qDebug() << __PRETTY_FUNCTION__ << item2->m_pItem;

//            int itemSize = sizeof(MyItem2);
//            void *p = malloc(itemSize);
//            memcpy((void*)item2, p, itemSize);
//            qDebug() << __PRETTY_FUNCTION__ << "@@" << itemSize << p;

//            delete item2;

//            item2->function2();
        }
    }

    if (m_pMyItem) {
        m_pMyItem->function();
        m_pMyItem->function2();
//        m_pMyItem->function21();
        qDebug() << __PRETTY_FUNCTION__ << m_pMyItem->m_pItem;

        disconnect(m_pMyItem, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyedFromQt(QObject*)));
        disconnect(m_pMyItem, SIGNAL(signalFromItemBase()), this, SLOT(onTriggeredFromItemBase()));
        disconnect(m_pMyItem, SIGNAL(signalFromMyItem()), this, SLOT(onTriggeredFromMyItem()));
    }
}

void ItemTest::onTriggeredFromItemBase()
{
    qDebug() << __PRETTY_FUNCTION__ << "MyItem:" << m_pMyItem;
    if (m_pMyItem) {
        m_pMyItem->function();
        m_pMyItem->function2();
//        m_pMyItem->function21();
    }
}

void ItemTest::onTriggeredFromMyItem()
{
    qDebug() << __PRETTY_FUNCTION__ << "MyItem:" << m_pMyItem;
    if (m_pMyItem) {
        m_pMyItem->function();
        m_pMyItem->function2();
        m_pMyItem->function21();
    }
}

void ItemTest::doCreate()
{
    qDebug() << __PRETTY_FUNCTION__ << "MyItem:" << m_pMyItem;
    if (m_pMyItem) {
        m_pMyItem->function();
        m_pMyItem->function2();
        m_pMyItem->function21();
    }

    if (NULL == m_pMyItem) {
        m_pMyItem = new MyItem2;
//        m_pMyItem->setParentItem(m_pItem);
//        m_pMyItem->setParent(m_pItem);

        connect(m_pMyItem, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyedFromQt(QObject*)));
        connect(m_pMyItem, SIGNAL(signalFromItemBase()), this, SLOT(onTriggeredFromItemBase()));
        connect(m_pMyItem, SIGNAL(signalFromMyItem()), this, SLOT(onTriggeredFromMyItem()));
    }
}

void ItemTest::doDestroy()
{
    qDebug() << __PRETTY_FUNCTION__ << "MyItem:" << m_pMyItem;
    if (m_pMyItem) {
        m_pMyItem->function();
        m_pMyItem->function2();
        m_pMyItem->function21();
    }

    if (m_pItem) {
        delete m_pItem;
        m_pItem = 0;
    }

    if (m_pMyItem) {
        delete m_pMyItem;
//        m_pMyItem->function();
//        m_pMyItem->function2();
//        m_pMyItem->function21();
        m_pMyItem = NULL;
    }
}
