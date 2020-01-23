#ifndef QUEUE_CPP
#define QUEUE_CPP
#include "queue.h"

template<typename T>
QueueP<T>::QueueP()
{
    count = 0;
}

template<typename T>
QueueP<T>::QueueP(int m)
{
    maxLength = m;			//Получаем размер
    A = new T[maxLength];	//Создаем очередь
    P = new T[maxLength];
    count = 0;				//изначально очередь пустая
}

// деструктор
template<typename T>
QueueP<T>::~QueueP()
{

        delete[] A;
        delete[] P;

}

template<typename T>
QueueP<T>::QueueP(const QueueP &_Q)
{
    try {
        // попытка выделить память
        A = new T[_Q.count];
        P = new int[_Q.count];
    }
    catch (bad_alloc e)
    {
        // если память не выделилась то обработать ошибку
        cout << e.what() << endl;
        count = 0;
        return;
    }

    // скопировать _Q => *this
    count = _Q.count;

    // поэлементное копирование данных
    for (int i = 0; i < count; i++)
        A[i] = _Q.A[i];

    for (int i = 0; i < count; i++)
        P[i] = _Q.P[i];
}

template<typename T>
void QueueP<T>::Push(T item, int priority)
{
    if (!IsFull())
    {
        A[count] = item;
        P[count] = priority;
        count++;
    }
}
// Функция, вытягивающая из очереди первый элемент
template<typename T>
T QueueP<T>::Pop()
{
    if (!IsEmpty())
    {
        int MaxP = P[0];	//приоритетный элемент нулевой
        int MaxPosP = 0;	//приоритетный индекс = 0

        for (int i = 1; i < count; i++)	//ищем приоритет
        {
            if (MaxP > P[i])	//если встречен более приоритетный элемент
            {
                MaxP = P[i];
                MaxPosP = i;
            }
        }

        T tempA = A[MaxPosP];	//вытаскиваем приоритетный элемент
        int tempP = P[MaxPosP];

        for (int i = MaxPosP; i < count - 1; i++)	//сдвигаем все элементы
        {
            A[i] = A[i + 1];
            P[i] = P[i + 1];
        }

        count--;	//уменьшаем количество
        return tempA;
    }
    else
        return -1;
}

template<typename T>
bool QueueP<T>::IsEmpty()
{
    return count == 0;
}

template<typename T>
bool QueueP<T>::IsFull()
{
    return count == maxLength;
}

template<typename T>
void QueueP<T>::Clear()
{
    count = 0;
}

template<typename T>
int QueueP<T>::Count()
{
    return count;
}
// Функция, выводящая очередь на экран
template<typename T>
void QueueP<T>::Print()
{
    cout << endl << "----------------------------------------" << endl;
    for (int i = 0; i < count; i++)
    {
        cout << A[i] << " - " << P[i] << endl << endl;
    }
    cout << endl << "----------------------------------------" << endl;
}
#endif
