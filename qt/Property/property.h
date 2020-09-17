#ifndef PROPERTY
#define PROPERTY

#include <QObject>
#include <QString>

class Property : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(QString name NOTIFY nameChanged WRITE setName READ name)

public:
    Property(QObject *parent = 0);
    ~Property();

    int age() const;
    void setAge(const int &age);

    QString name() const;
    void setName(const QString &name);

signals:
    void ageChanged();
    void nameChanged();

private:
    int m_age;
    QString m_name;
};

#endif // PROPERTY
