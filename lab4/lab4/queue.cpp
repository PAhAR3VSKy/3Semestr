#ifndef QUEUE_CPP
#define QUEUE_CPP
#include "queue.h"

template<typename T>
inline QueueP<T>::QueueP()
{
	count = 0;
}
// деструктор
template<typename T>
QueueP<T>::~QueueP()
{
	if (count > 0)
	{
		delete[] A;
		delete[] P;
	}
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
	// 1. Создать новый массив-очередь и массив-приоритет
	T* A2;
	int* P2;

	try {
		// попытка выделить память для нового массива
		A2 = new T[count + 1];
		P2 = new int[count + 1];
	}
	catch (bad_alloc e)
	{
		// если память не выделена, то выход
		cout << e.what() << endl;
		return;
	}

	// 2. Поиск позиции pos в массиве P согласно с приоритетом priority
	int pos;

	if (count == 0)
		pos = 0;
	else
	{
		pos = 0;
		while (pos < count)
		{
			if (P[pos] < priority) break;
			pos++;
		}
	}

	// 3. Копирование данных A2<=A; P2<=P
	// по формуле P = [0,1,...] + pos+1 + [pos+2,pos+3,...]
	// 3.1. Индексы массива с номерами 0..pos
	for (int i = 0; i < pos; i++)
	{
		A2[i] = A[i];
		P2[i] = P[i];
	}

	// 3.2. Добавить элемент в позиции pos
	A2[pos] = item;
	P2[pos] = priority;

	// 3.3. Элементы после позиции pos
	for (int i = pos + 1; i < count + 1; i++)
	{
		A2[i] = A[i - 1];
		P2[i] = P[i - 1];
	}

	// 4. Освободить память, предварительно выделенную для A и P
	if (count > 0)
	{
		delete[] A;
		delete[] P;
	}

	// 5. Перенаправить указатели A->A2, P->P2
	A = A2;
	P = P2;

	// 6. Увеличить количество элементов в очереди на 1
	count++;
}
// Функция, вытягивающая из очереди первый элемент
template<typename T>
T QueueP<T>::Pop()
{
	// 1. Проверка
	if (count == 0)
		return 0;

	// 2. Объявить временные массивы
	T* A2;
	int* P2;

	// 3. Попытка выделить память для A2, P2
	try {
		A2 = new T[count - 1]; // на 1 элемент меньше
		P2 = new int[count - 1];
	}
	catch (bad_alloc e)
	{
		// если память не выделена, то вернуть 0 и выход
		cout << e.what() << endl;
		return 0;
	}

	// 4. Запомнить первый элемент
	T item;
	item = A[0];

	// 5. Скопировать данные из массивов A=>A2, P=>P2 без первого элемента
	for (int i = 0; i < count - 1; i++)
	{
		A2[i] = A[i + 1];
		P2[i] = P[i + 1];
	}

	// 6. Освободить предварительно выделенную память для A, P
	if (count > 0)
	{
		delete[] A;
		delete[] P;
	}

	// 7. Поправить количество элементов в очереди
	count--;

	// 8. Перенаправить указатели A->A2, P->P2
	A = A2;
	P = P2;

	// 9. Вернуть первый элемент очереди
	return item;
}

template<typename T>
void QueueP<T>::Clear()
{
	if (count > 0)
	{
		delete[] A;
		delete[] P;
		count = 0;
	}
}

template<typename T>
int QueueP<T>::Count()
{
	return count;
}
// Функция, выводящая очередь на экран
template<typename T>
void QueueP<T>::Print(const char * objName)
{
	cout << "Object: " << objName << endl;
	for (int i = 0; i < count; i++)
		cout << A[i] << ":" << P[i] << "\t" << endl;
	cout << endl;
	cout << "---------------" << endl;
}
#endif 