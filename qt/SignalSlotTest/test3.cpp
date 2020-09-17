#include "test3.h"

#include <QDebug>

ItemBase3::ItemBase3(QQuickItem *parent)
    : QQuickItem(parent)
{
    setObjectName(QString("ItemBase3"));

    qDebug() << __PRETTY_FUNCTION__ << this;
}

ItemBase3::~ItemBase3()
{
    qDebug() << __PRETTY_FUNCTION__ << this;
}

void ItemBase3::onDestroyedFromItemBase3(QObject *object)
{
    Q_ASSERT(this == object);

    qDebug() << __PRETTY_FUNCTION__ << this;
}

MyItem3::MyItem3(QString name, QQuickItem *parent)
    : ItemBase3(parent)
{
    setObjectName(name);

    qDebug() << __PRETTY_FUNCTION__ << this;
}

MyItem3::~MyItem3()
{
    qDebug() << __PRETTY_FUNCTION__ << this;
}

void MyItem3::onDestroyedFromMyItem3(QObject *object)
{
    Q_ASSERT(this == object);

    qDebug() << __PRETTY_FUNCTION__ << this;
}

ItemHolder::ItemHolder(QQuickItem *parent)
    : QQuickItem(parent)
    , m_pChild(new MyItem3(QString("Child"), this))
    , m_pMyItem3(NULL)
    , m_pMyItem31(NULL)
    , m_pBrother(NULL)
{
    setObjectName(QString("ItemHolder"));

    qDebug() << __PRETTY_FUNCTION__ << this;
}

ItemHolder::~ItemHolder()
{
    qDebug() << __PRETTY_FUNCTION__ << this;

    qDebug() << __PRETTY_FUNCTION__ << "@@";
    if (m_pChild) {
        delete m_pChild;
        m_pChild = NULL;
    }
    qDebug() << __PRETTY_FUNCTION__ << "@@";


    if (m_pBrother) {
//        disconnect(m_pBrother, 0, 0, 0);
        disconnect(m_pBrother, 0, this, 0);

        delete m_pBrother;
        m_pBrother = NULL;
    }

//    disconnect(m_pMyItem3, 0, 0, 0);
//    disconnect(m_pMyItem31, 0, 0, 0);
    disconnect(m_pMyItem3, 0, this, 0);
    disconnect(m_pMyItem31, 0, this, 0);
}

void ItemHolder::setItem3(MyItem3 *item)
{
    qDebug() << __PRETTY_FUNCTION__ << this;
    qDebug() << __PRETTY_FUNCTION__ << "param" << item;

    if (NULL == m_pMyItem3) {
        m_pMyItem3 = item;

        if (m_pMyItem3) {
            connect(m_pMyItem3, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyedFromItemHolder(QObject*)));
        }
    }
    else {
        disconnect(m_pMyItem3, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyedFromItemHolder(QObject*)));

        m_pMyItem3 = item;

        if (m_pMyItem3) {
            connect(m_pMyItem3, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyedFromItemHolder(QObject*)));
        }
    }
}

void ItemHolder::setItem31(MyItem3 *item)
{
    qDebug() << __PRETTY_FUNCTION__ << this;
    qDebug() << __PRETTY_FUNCTION__ << "param" << item;

    if (NULL == m_pMyItem31) {
        m_pMyItem31 = item;

        if (m_pMyItem31) {
            connect(m_pMyItem31, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyedFromItemHolder(QObject*)));
        }
    }
    else {
        disconnect(m_pMyItem31, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyedFromItemHolder(QObject*)));

        m_pMyItem31 = item;

        if (m_pMyItem31) {
            connect(m_pMyItem31, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyedFromItemHolder(QObject*)));
        }
    }
}

void ItemHolder::setBrother(ItemHolder *item)
{
    qDebug() << __PRETTY_FUNCTION__ << this;
    qDebug() << __PRETTY_FUNCTION__ << "param" << item;

    if (NULL == m_pBrother) {
        m_pBrother = item;

        if (m_pBrother) {
            connect(m_pBrother, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyedFromItemHolder(QObject*)));
        }
    }
    else {
        disconnect(m_pBrother, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyedFromItemHolder(QObject*)));

        m_pBrother = item;

        if (m_pBrother) {
            connect(m_pBrother, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyedFromItemHolder(QObject*)));
        }
    }
}

void ItemHolder::onDestroyedFromItemHolder(QObject *object)
{
    qDebug() << __PRETTY_FUNCTION__ << this;
    qDebug() << __PRETTY_FUNCTION__ << "object:" << object;

    if (m_pMyItem3 == object) {
        qDebug() << __PRETTY_FUNCTION__ << "MyItem3";

        disconnect(m_pMyItem3, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyedFromItemHolder(QObject*)));
        m_pMyItem3 = NULL;
    }
    else if (m_pMyItem31 == object) {
        qDebug() << __PRETTY_FUNCTION__ << "MyItem31";

        disconnect(m_pMyItem31, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyedFromItemHolder(QObject*)));
        m_pMyItem31 = NULL;
    }
    else {
        qDebug() << __PRETTY_FUNCTION__ << "Others";
    }
}

ItemTest3::ItemTest3(QQuickItem *parent)
    : QQuickItem(parent)
    , m_bCreated(false)
    , m_pItemHolder(NULL)
    , m_pItemHolder2(NULL)
    , m_pMyItem3(NULL)
    , m_pMyItem31(NULL)
{
    setObjectName(QString("ItemTest"));

    qDebug() << __PRETTY_FUNCTION__ << this;
}

ItemTest3::~ItemTest3()
{
    qDebug() << __PRETTY_FUNCTION__ << this;
}

void ItemTest3::doCreate()
{
    qDebug() << __PRETTY_FUNCTION__ << this;

    if (!m_bCreated) {
        m_bCreated = true;

        m_pItemHolder = new ItemHolder(this);
        m_pMyItem3 = new MyItem3(QString("MyItem3"), m_pItemHolder);
        m_pMyItem31 = new MyItem3(QString("MyItem31"), m_pItemHolder);
        m_pItemHolder->setItem3(m_pMyItem3);
        m_pItemHolder->setItem31(m_pMyItem31);

        m_pItemHolder2 = new ItemHolder(this);
        m_pItemHolder->setBrother(m_pItemHolder2);

        connect(m_pMyItem3, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyedFromItemTest3(QObject*)));
        connect(m_pMyItem31, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyedFromItemTest3(QObject*)));
        connect(m_pItemHolder2, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyedFromItemTest3(QObject*)));
    }
}

void ItemTest3::doDestroy()
{
    qDebug() << __PRETTY_FUNCTION__ << this;

    if (m_pItemHolder) {
        delete m_pItemHolder;
        m_pItemHolder = NULL;
    }
}

void ItemTest3::doCheck()
{
    qDebug() << __PRETTY_FUNCTION__ << this;

    if (m_pItemHolder) {
        qDebug() << __PRETTY_FUNCTION__ << "ItemHolder" << m_pItemHolder->objectName();
    }
    if (m_pMyItem3) {
        qDebug() << __PRETTY_FUNCTION__ << "MyItem3" << m_pMyItem3->objectName();
    }
    if (m_pMyItem31) {
        qDebug() << __PRETTY_FUNCTION__ << "MyItem31" << m_pMyItem31->objectName();
    }
    if (m_pItemHolder2) {
        qDebug() << __PRETTY_FUNCTION__ << "Brother" << m_pItemHolder2->objectName();
    }
}

void ItemTest3::onDestroyedFromItemTest3(QObject *object)
{
    qDebug() << __PRETTY_FUNCTION__ << this;
    qDebug() << __PRETTY_FUNCTION__ << "object:" << object;

    if (m_pMyItem3 == object) {
        qDebug() << __PRETTY_FUNCTION__ << "MyItem3";

        disconnect(m_pMyItem3, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyedFromItemTest3(QObject*)));
        m_pMyItem3 = NULL;
    }
    else if (m_pMyItem31 == object) {
        qDebug() << __PRETTY_FUNCTION__ << "MyItem31";

        disconnect(m_pMyItem31, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyedFromItemTest3(QObject*)));
        m_pMyItem31 = NULL;
    }
    else if (m_pItemHolder2 == object) {
        qDebug() << __PRETTY_FUNCTION__ << "Brother";

        disconnect(m_pItemHolder2, SIGNAL(destroyed(QObject*)), this, SLOT(onDestroyedFromItemTest3(QObject*)));
        m_pItemHolder2 = NULL;
    }
    else {
        qDebug() << __PRETTY_FUNCTION__ << "Others";
    }
}
