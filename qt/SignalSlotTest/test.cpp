#include "test.h"

#include <QDebug>

ItemBase::ItemBase()
{
    qDebug() << __PRETTY_FUNCTION__;
}

ItemBase::~ItemBase()
{
    qDebug() << __PRETTY_FUNCTION__;

//    emit signalTriggered();
    emit visibleChanged();
    emit enabledChanged();
}

MyItem::MyItem()
{
    qDebug() << __PRETTY_FUNCTION__;

    connect(this, SIGNAL(signalTriggered()), this, SLOT(onSignalTriggered()));
    connect(this, SIGNAL(visibleChanged()), this, SLOT(onVisibleChanged()));
    connect(this, SIGNAL(enabledChanged()), this, SLOT(onEnableChanged()));
}

MyItem::~MyItem()
{
    qDebug() << __PRETTY_FUNCTION__;

    emit signalTriggered();
}

void MyItem::onVisibleChanged()
{
    qDebug() << __PRETTY_FUNCTION__;
}

void MyItem::onEnableChanged()
{
    qDebug() << __PRETTY_FUNCTION__;
}

void MyItem::onSignalTriggered()
{
    qDebug() << __PRETTY_FUNCTION__;
}

void MyItem::onMouseClicked()
{
    qDebug() << __PRETTY_FUNCTION__;

    delete this;
}

void MyItem::onMouseClicked2()
{
    qDebug() << __PRETTY_FUNCTION__;

    MyItem();
}
