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
    bool interruptFlag;
    for(int i = 0; i < m_count; i++)
    {
        interruptFlag = true;
        for(int j = 0 ; j < m_count - i - 1; j++)
        {
            if(arrayTime[j] > arrayTime[j+1])
            {
                int temp = arrayTime[j];
                arrayTime[j] = arrayTime[j+1];
                arrayTime[j+1] = temp;
                interruptFlag = false;
            }
        }
        if(interruptFlag)
            break;
    }
}

void stream::run()// переделать цикл, не работает таймер и каждый самолет первый, сделать цикл правильно
{
    QueueP<int> Up(m_count);
    QueueP<int> Down(m_count);
    int timerCount = 0;
    int numberUpDown = 1;
    arrayTimeUp = new int[m_count] {0};
    arrayTimeDown = new int[m_count] {0};
    //memset(arrayTimeUp, 1000, m_count*sizeof (int));
    //memset(arrayTimeDown, 1000, m_count*sizeof (int));
    timer = 0;
    while(m_running && (!Up.IsFull() || !Down.IsFull()))
    {
        sequence = rand()%2;
        if(sequence)
        {
            while(!Up.IsFull())
            {
                int fastInterval = rand()%m_interval + timer;
                if(!checkArray(arrayTimeUp, arrayTimeDown, fastInterval))
                    break;
                arrayTimeUp[0] = fastInterval;
                sortArrayTime(arrayTimeUp);
                Up.Push(numberUpDown, fastInterval);
                emit send(fastInterval, 0, numberUpDown, 0);
                for(int i = 0; i < timer; i++)
                {
                    if(timer == arrayTimeUp[i])
                    {
                        numberPlane = Up.Pop();
                        emit send(timer, 1, numberPlane, 0);
                    }
                }
                /*if((timer == arrayTimeUp[timer]) && (timer != 0))
                {
                    numberPlane = Up.Pop();
                    emit send(timer, 1, numberPlane, 0);
                    timerCount++;
                }*/
                timer++;
                numberUpDown++;
                Sleep(1000);
                break;
            }
        }
        else
        {
            while(!Down.IsFull())
            {
                int fastInterval = rand()%m_interval + timer;
                if(!checkArray(arrayTimeUp, arrayTimeDown, fastInterval))
                    break;
                arrayTimeDown[0] = fastInterval;
                sortArrayTime(arrayTimeDown);
                Down.Push(numberUpDown, fastInterval);
                emit send(fastInterval, 0, numberUpDown, 1);
                for(int i = 0; i < timer; i++)
                {
                    if(timer == arrayTimeDown[i])
                    {
                        numberPlane = Down.Pop();
                        emit send(timer, 1, numberPlane, 1);
                    }
                }
                /*if((timer == arrayTimeDown[timer]) && (timer != 0))
                {
                    numberPlane = Down.Pop();
                    emit send(timer, 1, numberPlane, 1);
                    timerCount++;
                }*/
                timer++;
                numberUpDown++;
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








