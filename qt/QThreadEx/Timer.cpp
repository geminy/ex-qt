#include <QTimerEvent>
#include <QTime>
#include <QThread>
#include <QDebug>
#include "Timer.h"

Timer::Timer(QObject *parent)
    : QObject(parent)
{
    qDebug() << "Timer::Timer";
}

void Timer::startsTimer(int msec)
{
    m_timerId = startTimer(msec);
    qDebug() << "Timer::startsTimer id:" << m_timerId;
    qDebug() << "current thread:" << thread();
}

void Timer::killsTimer()
{
    qDebug() << "Timer::killsTimer";
    killTimer(m_timerId);
}

void Timer::timerEvent(QTimerEvent *event)
{
    qDebug() << "Timer::timerEvent";
    if (!event) {
        return;
    }
    qDebug() << "@@ timer id:" << event->timerId() << "time:" << QTime::currentTime().toString();
}
