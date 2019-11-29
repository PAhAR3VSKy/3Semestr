#ifndef QUEUE_H
#define QUEUE_H
#include <cassert>
#include <iostream>
#include <queue>

using namespace std;

template <typename T>
class QueueP
{
private:
	T* A; // динамический массив элементов типа T
	int* P; // массив приоритетов
	int count; // количество элементов в очереди
public:
	QueueP();
	~QueueP();
	QueueP(const QueueP&);
	void Push(T item, int priority);
	T Pop();
	void Clear();
	int Count();
	void Print(const char* objName);
};
#include "queue.cpp"
#endif 


