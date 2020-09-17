#include <QTimer>
#include <QTime>
#include <QDebug>
#include "Thread.h"

Thread::Thread(QThread *parent)
    : QThread(parent), m_timer(new QTimer())
{
    qDebug() << "Thread::Thread";
    connect(this, SIGNAL(started()), m_timer, SLOT(start()));
    connect(m_timer, SIGNAL(timeout()), this, SLOT(onTimeout()), Qt::DirectConnection);
    connect(this, SIGNAL(finished()), m_timer, SLOT(stop()));
    connect(this, SIGNAL(finished()), SLOT(onThreadQuit()));
}

Thread::~Thread()
{
    qDebug() << "Thread::~Thread";
    quit();
    wait();
    if (m_timer && !m_timer->isActive()) {
        delete m_timer; // may problem
        m_timer = NULL;
    }
}

void Thread::onTimeout()
{
    qDebug() << "Thread::onTimeout time:" << QTime::currentTime().toString();
}

void Thread::startWork()
{
    qDebug() << "Thread::startWork";
    if (m_timer) {
        m_timer->setInterval(1000);
        m_timer->moveToThread(this);
        qDebug() << "work thread:" << m_timer->thread();
        start();
    }
}

void Thread::onThreadQuit()
{
    qDebug() << "Thread::onThreadQuit";
//    if (m_timer && m_timer->isActive()) {
//        m_timer->stop(); // Timers cannot be stopped from another thread
//        delete m_timer;
//        m_timer = NULL;
//    }
}
