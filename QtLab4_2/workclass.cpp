#include "workclass.h"

WorkClass::WorkClass()
{

}
void WorkClass::doWork(int count, int interval)
{
    QueueP<int> P(count);
    int i = 0;
    while(!P.IsFull())
    {
        P.Push(i+1, 1);
    }

    for (int j = 0;P.IsEmpty();j++) {
        int d = P.Pop();
        emit send(d);
        Sleep(1000);
    }
}
