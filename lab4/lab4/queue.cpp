#include "queue.h"

template<typename T> queue<T>::queue(int sizeQueue) :
	size(sizeQueue), // инициализация константы
	begin(0), end(0), elemCT(0)
{
	// дополнительная позици поможет нам различать конец и начало очереди
	queuePtr = new T[size + 1];
}

template<typename T> queue<T>::queue(const queue& otherQueue) :
	size(otherQueue.size), begin(otherQueue.begin),
	end(otherQueue.end), elemCT(otherQueue.elemCT),
	queuePtr(new T[size + 1])
{
	for (int ix = 0; ix < size; ix++)
		queuePtr[ix] = otherQueue.queuePtr[ix]; // копируем очередь
}

template<typename T>
queue<T>::~queue()
{
	delete[] queuePtr;
}

// функция добавления элемента в очередь
template<typename T> void queue<T>::enqueue(const T& newElem)
{
	// проверяем, ести ли свободное место в очереди
	assert(elemCT < size);

	// обратите внимание на то, что очередь начинает заполняться с 0 индекса
	queuePtr[end++] = newElem;

	elemCT++;

	// проверка кругового заполнения очереди
	if (end > size)
		end -= size + 1; // возвращаем end на начало очереди
}

// функция удаления элемента из очереди
template<typename T> T queue<T>::dequeue()
{
	// проверяем, есть ли в очереди элементы
	assert(elemCT > 0);

	T returnValue = queuePtr[begin++];
	elemCT--;

	// проверка кругового заполнения очереди
	if (begin > size)
		begin -= size + 1; // возвращаем behin на начало очереди

	return returnValue;
}

template<typename T> void queue<T>::printQueue()
{
	cout << "Очередь: ";

	if (end == 0 && begin == 0)
		cout << " пустая\n";
	else
	{
		for (int ix = end; ix >= begin; ix--)
			cout << queuePtr[ix] << " ";
		cout << endl;
	}
}
//http://cppstudio.com/post/5159/