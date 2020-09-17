#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QThread>
#include "Timer.h"
#include "Thread.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    qDebug() << "main thread:" << QThread::currentThread();

//    Timer timer;
//    timer.startsTimer(); // in main thread, wait
//    QThread::sleep(5);
//    timer.killsTimer(); // in main thread, no effect if killing timer

//    Thread thread; // stack var, thread no quit
//    thread.startWork(); // in work thread, no wait
//    QThread::sleep(5);

    Thread *thread = new Thread();
    if (thread) {
        thread->startWork();
    }
    QThread::sleep(5);
    if (thread) {
        delete thread;
        thread  = NULL;
    }

    return app.exec();
}
