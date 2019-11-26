#include "queue.h"

template<typename T> queue<T>::queue(int sizeQueue) :
	size(sizeQueue), // ������������� ���������
	begin(0), end(0), elemCT(0)
{
	// �������������� ������ ������� ��� ��������� ����� � ������ �������
	queuePtr = new T[size + 1];
}

template<typename T> queue<T>::queue(const queue& otherQueue) :
	size(otherQueue.size), begin(otherQueue.begin),
	end(otherQueue.end), elemCT(otherQueue.elemCT),
	queuePtr(new T[size + 1])
{
	for (int ix = 0; ix < size; ix++)
		queuePtr[ix] = otherQueue.queuePtr[ix]; // �������� �������
}

template<typename T>
queue<T>::~queue()
{
	delete[] queuePtr;
}

// ������� ���������� �������� � �������
template<typename T> void queue<T>::enqueue(const T& newElem)
{
	// ���������, ���� �� ��������� ����� � �������
	assert(elemCT < size);

	// �������� �������� �� ��, ��� ������� �������� ����������� � 0 �������
	queuePtr[end++] = newElem;

	elemCT++;

	// �������� ��������� ���������� �������
	if (end > size)
		end -= size + 1; // ���������� end �� ������ �������
}

// ������� �������� �������� �� �������
template<typename T> T queue<T>::dequeue()
{
	// ���������, ���� �� � ������� ��������
	assert(elemCT > 0);

	T returnValue = queuePtr[begin++];
	elemCT--;

	// �������� ��������� ���������� �������
	if (begin > size)
		begin -= size + 1; // ���������� behin �� ������ �������

	return returnValue;
}

template<typename T> void queue<T>::printQueue()
{
	cout << "�������: ";

	if (end == 0 && begin == 0)
		cout << " ������\n";
	else
	{
		for (int ix = end; ix >= begin; ix--)
			cout << queuePtr[ix] << " ";
		cout << endl;
	}
}
//http://cppstudio.com/post/5159/