#pragma once
#include <iostream>

template<typename T> class queue
{
private:
	T* queuePtr;     // указатель на очередь
	const int size;  // максимальное количество элементов в очереди
	int begin,       // начало очереди
		end;         // конец очереди
	int elemCT;      // счетчик элементов
public:
	queue(int);					// конструктор по умолчанию
	queue(const queue<T>&);		// конструктор копирования
	~queue();					// деструктор
	void enqueue(const T&);		// добавить элемент в очередь
	T dequeue();				// удалить элемент из очереди
	void printQueue();

};



