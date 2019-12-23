#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>

using namespace std;
// Очередь с приоритетами для типа T
template <typename T>
class QueueP
{
private:
    T* A;								// динамический массив элементов типа T
    int* P;								// массив приоритетов
    int count;							// количество элементов в очереди
    int maxLength;						// максимальный размер очереди
public:
    QueueP(int);						// конструктор без параметров
    ~QueueP();							// деструктор
    QueueP(const QueueP&);				// конструктор копирования
    void Push(T item, int priority);	// функция, добавляющая в очередь новый элемент
    T Pop();							// функция, витягивающая из очереди первый элемент
    bool IsEmpty();						// Проверка существования элементов в очереди
    bool IsFull();						// Проверка на переполнение очереди
    void Clear();						// очистка очереди
    int Count();						// возвращает количество элементов в очереди
    void Print();						// функция, выводящая очередь
};
#include "queue.cpp"
#endif


