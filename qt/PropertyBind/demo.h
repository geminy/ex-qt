#ifndef DEMO
#define DEMO

#include <QObject>
#include <iostream>

class Demo : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int age READ age WRITE setAge NOTIFY ageChanged)
    Q_PROPERTY(bool ageover READ ageover WRITE setAgeover NOTIFY ageoverChanged)
    Q_PROPERTY(bool show READ show WRITE setShow NOTIFY showChanged)

public:
    explicit Demo(QObject *parent = 0)
        : QObject(parent), m_age(0), m_ageOver(false), m_show(false)
    {
        std::cout << "Demo::Demo" << std::endl;
    }

    ~Demo()
    {
        std::cout << "Demo::~Demo" << std::endl;
    }

    int age() const
    {
        std::cout << "Demo::age" << std::endl;
        return m_age;
    }

    void setAge(const int &a)
    {
        std::cout << "Demo::setAge age: " << a << std::endl;
        m_age = a;
        emit ageChanged();

        if (m_age > 100 && m_age < 300) {
            setAgeover(true);
        }
        else {
            setAgeover(false);
        }
    }

    bool ageover() const
    {
        std::cout << "Demo::ageover" << std::endl;
        return m_ageOver;
    }

    void setAgeover(const bool &over)
    {
        std::cout << "Demo::setAgeover over: " << over << std::endl;
        m_ageOver = over;
        emit ageoverChanged();
    }

    bool show() const
    {
        std::cout << "Demo::show ? " << m_show << std::endl;
        return m_show;
    }

    void setShow(bool s)
    {
        std::cout << "Demo::setShow ? " << s << std::endl;
        m_show = s;
        emit showChanged();
    }

    Q_INVOKABLE void btnClicked()
    {
        std::cout << "Demo::btnClicked" << std::endl;
        if (m_show) {
            setShow(false);
        }
        else {
            setShow(true);
        }
    }

signals:
    void ageChanged();
    void ageoverChanged();
    void showChanged();

private:
    int m_age;
    bool m_ageOver;
    bool m_show;
};

#endif // DEMO
