#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QQuickItem>
#include <QQmlListProperty>
#include <QList>
#include <QDebug>

class ButtonText : public QQuickItem
{
    Q_OBJECT

public:
    ButtonText(QString text = QString(), int index = -1, QQuickItem *parent = 0)
        : QQuickItem(parent), m_text(text), m_index(index)
    {
        qDebug() << __PRETTY_FUNCTION__ << m_text << m_index;
    }

    ~ButtonText()
    {
        qDebug() << __PRETTY_FUNCTION__ << m_text << m_index;
        emit buttonTextDestroyed(m_index);
    }

    Q_INVOKABLE QString buttonText()
    {
        qDebug() << __PRETTY_FUNCTION__ << m_text << m_index;
        return m_text;
    }

signals:
    void buttonTextDestroyed(int index);

private:
    QString m_text;
    int m_index;
};

class MyItem;

class MyButton : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<ButtonText> btnTextList READ btnTextList)

public:
    explicit MyButton(QQuickItem *parent = 0)
        : QQuickItem(parent)
    {
        qDebug() << __PRETTY_FUNCTION__;
    }

    ~MyButton()
    {
        qDebug() << __PRETTY_FUNCTION__;
    }

    QQmlListProperty<ButtonText> btnTextList()
    {
        qDebug() << __PRETTY_FUNCTION__;
        return QQmlListProperty<ButtonText>(this, m_btnTextList);
    }

    void setBtnTexts(QList<ButtonText*> texts)
    {
        qDebug() << __PRETTY_FUNCTION__;
        if (m_btnTextList.empty()) {
            m_btnTextList = texts;
            for (int i = 0; i < btnTextListCount(); ++i) {
                ButtonText *t = m_btnTextList.value(i);
                if (t) {
                    connect(t, &ButtonText::buttonTextDestroyed, this, &MyButton::onBtnTextDestroyed);
                }
            }
        }
    }

    int btnTextListCount() {
        return m_btnTextList.count();
    }

private slots:
    void onBtnTextDestroyed(int index)
    {
        qDebug() << __PRETTY_FUNCTION__;
        if (index >= 0 && index < btnTextListCount()) {
            m_btnTextList.replace(index, NULL);
        }
    }

private:
    friend class MyItem;
    QList<ButtonText*> m_btnTextList;
};

class MyItem : public QQuickItem
{
    Q_OBJECT

public:
    MyItem(QQuickItem *parent = 0)
        : QQuickItem(parent), m_pButton(new MyButton)
    {
        qDebug() << __PRETTY_FUNCTION__;
    }

    ~MyItem()
    {
        qDebug() << __PRETTY_FUNCTION__;
        if (m_pButton) {
            delete m_pButton;
            m_pButton = NULL;
        }
    }

    Q_INVOKABLE void createBtnTexts()
    {
        qDebug() << __PRETTY_FUNCTION__;
        if (m_pButton && !m_pButton->btnTextListCount()) {
            QList<ButtonText*> btnTextList;
            ButtonText *bt0= new ButtonText(QString("text0"), 0);
            btnTextList.push_back(bt0);
            ButtonText *bt1= new ButtonText(QString("text1"), 1);
            btnTextList.push_back(bt1);
            m_pButton->setBtnTexts(btnTextList);
        }
    }

    Q_INVOKABLE void deleteBtnTexts()
    {
        qDebug() << __PRETTY_FUNCTION__;
        if (m_pButton) {
            ButtonText *t = m_pButton->m_btnTextList[0];
            if (t) {
                delete t;
            }
        }
    }

    Q_INVOKABLE void checkBtnTexts()
    {
        qDebug() << __PRETTY_FUNCTION__;
        if (m_pButton) {
            for (int i = 0; i < m_pButton->btnTextListCount(); ++i) {
                ButtonText *t = m_pButton->m_btnTextList[i];
                if (t) {
                    t->buttonText();
                }
            }
        }
    }

    Q_INVOKABLE MyButton* getButton()
    {
        qDebug() << __PRETTY_FUNCTION__;
        return m_pButton;
    }

private:
    MyButton *m_pButton;
};

#endif // MYBUTTON_H

