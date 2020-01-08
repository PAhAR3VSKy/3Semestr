#include "stream.h"



stream::stream(QObject *parent):
    QObject(parent)
{

}

bool stream::running() const
{
    return m_running;
}

QString stream::message() const
{
    return m_message;
}

int stream::count() const
{
    return m_count;
}

int stream::interval() const
{
    return m_interval;
}

void stream::run()
{
    timer = 0;
    while(m_running)
    {

            sequence = rand()%2;
            if(sequence)
            {
                while(!Up.IsFull())
                {
                    int fastInterval = rand()%m_count + timer;
                    Up.Push(1, fastInterval);
                    timer++;
                    Sleep(1000);
                    break;
                }
            }
            else
            {

            }


        // КОД через m_count создаем очередь определенного размера
        // m_interval задаем интервал появления самолетов
        // outFunc передает номер и время прилета самолета
        // создать статус самолета взлет или посадка
        for(int i = 0; i < m_count; i++)
        {
            emit send(i, true);
            Sleep(1000);
        }
    }
    emit finished();
}

void stream::setRunning(bool running)
{
    if (m_running == running)
        return;

    m_running = running;
    emit runningChanged(m_running);
}

void stream::setMessage(QString message)
{
    if (m_message == message)
        return;

    m_message = message;
    emit messageChanged(m_message);
}

void stream::setCount(int count)
{
    if (m_count == count)
        return;

    m_count = count;
    emit countChanged(m_count);
}

void stream::setInterval(int interval)
{
    if (m_interval == interval)
        return;

    m_interval = interval;
    emit intervalChanged(m_interval);
}








