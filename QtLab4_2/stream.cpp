#include "stream.h"



stream::stream(QObject *parent):
    QObject(parent)
{

}

stream::~stream()
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

bool stream::checkArray(int *Up, int *Down, int interval)
{
    bool result = true;
    for(int i = 0; i < m_count; i++)
    {
        if(Up[i] == interval || Down[i] == interval)
            result = false;
    }
    return result;
}

void stream::sortArrayTime(int *arrayTime)
{
    key = 0;
    temp = 0;
    for(int i = 0; arrayTime[i]!=0; i++)
    {
        key = i + 1;
        temp = arrayTime[key];
        for(int j = i + 1; j>0; j--)
        {
            if(temp<arrayTime[j - 1])
            {
                arrayTime[j] = arrayTime[j-1];
                key = j - 1;
            }
        }
        arrayTime[key] = temp;
    }
}

void stream::run()
{
    QueueP<int> Up(m_count);
    QueueP<int> Down(m_count);
    memset(arrayTimeUp, 0, m_count*sizeof (int));
    memset(arrayTimeDown, 0, m_count*sizeof (int));
    timer = 0;
    while(m_running)
    {
        sequence = rand()%2;
        if(sequence)
        {
            for(int numberUp = 1; numberUp < Up.Count()+1; numberUp++)
            {
                int fastInterval = rand()%m_interval + timer;
                if(!checkArray(arrayTimeUp, arrayTimeDown, fastInterval))
                {
                    numberUp--;
                    break;
                }
                arrayTimeUp[timer] = fastInterval;
                sortArrayTime(arrayTimeUp);
                Up.Push(numberUp, fastInterval);
                emit send(fastInterval, 0, numberUp, 0);
                timer++;
                if(timer == arrayTimeUp[timer])
                {
                    numberPlane = Up.Pop();
                    emit send(timer, 1, numberPlane, 0);
                }
                Sleep(1000);
                break;
            }
        }
        else
        {
            for(int numberDown = 1; numberDown < Down.Count(); numberDown++)
            {
                int fastInterval = rand()%m_interval + timer;
                if(!checkArray(arrayTimeUp, arrayTimeDown, fastInterval))
                {
                    numberDown--;
                    break;
                }
                arrayTimeDown[timer] = fastInterval;
                sortArrayTime(arrayTimeDown);
                Down.Push(numberDown, fastInterval);
                emit send(fastInterval, 0, numberDown, 1);
                timer++;
                if(timer == arrayTimeDown[timer])
                {
                    numberPlane = Down.Pop();
                    emit send(timer, 1, numberPlane, 1);
                }
                Sleep(1000);
                break;
            }
        }
    }
    emit finished();
    //////////////////////////////////////////////////////////////////////////////////////////////////////



        // если момент появления равный, у одного из самолетов увеличивать время на 1
        // КОД через m_count создаем очередь определенного размера
        // m_interval задаем интервал появления самолетов
        // outFunc передает номер и время прилета самолета
        // создать статус самолета взлет или посадка


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








