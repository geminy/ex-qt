#include "property.h"
#include <QDebug>

Property::Property(QObject *parent)
    : QObject(parent)
{
    qDebug() << "Property::Property";
}

Property::~Property()
{
    qDebug() << "Property::~Property";
}

int Property::age() const
{
    qDebug() << "Property::age" << m_age;
    return m_age;
}

void Property::setAge(const int &age)
{
    qDebug() << "Property::setAge" << age;
    m_age = age;
    emit ageChanged();
}

QString Property::name() const
{
    qDebug() << "Property::name" << m_name;
    return m_name;
}

void Property::setName(const QString &name)
{
    qDebug() << "Property::setName" << name;
    m_name = name;
    emit nameChanged();
}
