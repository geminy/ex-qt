#ifndef TIMER
#define TIMER

#include <QObject>

class QTimerEvent;

class Timer : public QObject
{
    Q_OBJECT

public:
    explicit Timer(QObject *parent = 0);

    void startsTimer(int msec = 1000);
    void killsTimer();

private:
    void timerEvent(QTimerEvent *event);

    int m_timerId;
};

#endif // TIMER
