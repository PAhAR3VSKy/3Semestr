#ifndef QUEUE_H
#define QUEUE_H
#include <cassert>
#include <iostream>
#include <queue>

using namespace std;
// ќчередь с приоритетами дл€ типа T
template <typename T>
class QueueP
{
private:
	T* A;								// динамический массив элементов типа T
	int* P;								// массив приоритетов
	int count;							// количество элементов в очереди
public:
	QueueP();							// конструктор без параметров
	~QueueP();							// деструктор
	QueueP(const QueueP&);				// конструктор копировани€
	void Push(T item, int priority);	// функци€, добавл€юща€ в очередь новый элемент
	T Pop();							// функци€, вит€гивающа€ из очереди первый элемент
	void Clear();						// очистка очереди
	int Count();						// возвращает количество элементов в очереди
	void Print(const char* objName);	// функци€, вывод€ща€ очередь
};
#include "queue.cpp"
#endif 


