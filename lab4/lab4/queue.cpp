#ifndef QUEUE_CPP
#define QUEUE_CPP
#include "queue.h"

template<typename T>
inline QueueP<T>::QueueP()
{
	count = 0;
}
// ����������
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
		// ������� �������� ������
		A = new T[_Q.count];
		P = new int[_Q.count];
	}
	catch (bad_alloc e)
	{
		// ���� ������ �� ���������� �� ���������� ������
		cout << e.what() << endl;
		count = 0;
		return;
	}

	// ����������� _Q => *this
	count = _Q.count;

	// ������������ ����������� ������
	for (int i = 0; i < count; i++)
		A[i] = _Q.A[i];

	for (int i = 0; i < count; i++)
		P[i] = _Q.P[i];
}

template<typename T>
void QueueP<T>::Push(T item, int priority)
{
	// 1. ������� ����� ������-������� � ������-���������
	T* A2;
	int* P2;

	try {
		// ������� �������� ������ ��� ������ �������
		A2 = new T[count + 1];
		P2 = new int[count + 1];
	}
	catch (bad_alloc e)
	{
		// ���� ������ �� ��������, �� �����
		cout << e.what() << endl;
		return;
	}

	// 2. ����� ������� pos � ������� P �������� � ����������� priority
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

	// 3. ����������� ������ A2<=A; P2<=P
	// �� ������� P = [0,1,...] + pos+1 + [pos+2,pos+3,...]
	// 3.1. ������� ������� � �������� 0..pos
	for (int i = 0; i < pos; i++)
	{
		A2[i] = A[i];
		P2[i] = P[i];
	}

	// 3.2. �������� ������� � ������� pos
	A2[pos] = item;
	P2[pos] = priority;

	// 3.3. �������� ����� ������� pos
	for (int i = pos + 1; i < count + 1; i++)
	{
		A2[i] = A[i - 1];
		P2[i] = P[i - 1];
	}

	// 4. ���������� ������, �������������� ���������� ��� A � P
	if (count > 0)
	{
		delete[] A;
		delete[] P;
	}

	// 5. ������������� ��������� A->A2, P->P2
	A = A2;
	P = P2;

	// 6. ��������� ���������� ��������� � ������� �� 1
	count++;
}
// �������, ������������ �� ������� ������ �������
template<typename T>
T QueueP<T>::Pop()
{
	// 1. ��������
	if (count == 0)
		return 0;

	// 2. �������� ��������� �������
	T* A2;
	int* P2;

	// 3. ������� �������� ������ ��� A2, P2
	try {
		A2 = new T[count - 1]; // �� 1 ������� ������
		P2 = new int[count - 1];
	}
	catch (bad_alloc e)
	{
		// ���� ������ �� ��������, �� ������� 0 � �����
		cout << e.what() << endl;
		return 0;
	}

	// 4. ��������� ������ �������
	T item;
	item = A[0];

	// 5. ����������� ������ �� �������� A=>A2, P=>P2 ��� ������� ��������
	for (int i = 0; i < count - 1; i++)
	{
		A2[i] = A[i + 1];
		P2[i] = P[i + 1];
	}

	// 6. ���������� �������������� ���������� ������ ��� A, P
	if (count > 0)
	{
		delete[] A;
		delete[] P;
	}

	// 7. ��������� ���������� ��������� � �������
	count--;

	// 8. ������������� ��������� A->A2, P->P2
	A = A2;
	P = P2;

	// 9. ������� ������ ������� �������
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
// �������, ��������� ������� �� �����
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