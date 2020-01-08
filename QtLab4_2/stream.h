#ifndef STREAM_H
#define STREAM_H

#include <QObject>
#include <QString>
#include <QThread>
#include "queue.h"
#include "windows.h"


class stream:public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool running READ running WRITE setRunning NOTIFY runningChanged)
    Q_PROPERTY(QString message READ message WRITE setMessage NOTIFY messageChanged)
    Q_PROPERTY(int count READ count WRITE setCount NOTIFY countChanged)
    Q_PROPERTY(int interval READ interval WRITE setInterval NOTIFY intervalChanged)
public:
    explicit stream(QObject *parent = 0);
    bool running() const;
    QString message() const;
    int count() const;
    int interval() const;

public slots:
    void run();
    void setRunning(bool running);
    void setMessage(QString message);
    void setCount(int count);
    void setInterval(int interval);

signals:
    void finished();
    void send(int, bool);
    void runningChanged(bool running);
    void messageChanged(QString message);
    void countChanged(int count);
    void intervalChanged(int interval);

private:
    QueueP<int> Up;
    QueueP<int> Down;
    bool m_running;
    int m_count;
    int m_interval;
    QString m_message;
    int timer;
    bool sequence;
    bool DelOrAdd;
};

#endif // STREAM_H
