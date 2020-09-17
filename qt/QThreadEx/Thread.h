#ifndef THREAD
#define THREAD

#include <QThread>

class QTimer;

class Thread : public QThread
{
    Q_OBJECT

public:
    explicit Thread(QThread *parent = 0);
    ~Thread();

    void startWork();

public slots:
    void onTimeout();
    void onThreadQuit();

private:
    QTimer *m_timer;
};

#endif // THREAD
