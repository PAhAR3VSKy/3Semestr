#pragma once
#include <iostream>

template<typename T> class queue
{
private:
	T* queuePtr;     // ��������� �� �������
	const int size;  // ������������ ���������� ��������� � �������
	int begin,       // ������ �������
		end;         // ����� �������
	int elemCT;      // ������� ���������
public:
	queue(int);					// ����������� �� ���������
	queue(const queue<T>&);		// ����������� �����������
	~queue();					// ����������
	void enqueue(const T&);		// �������� ������� � �������
	T dequeue();				// ������� ������� �� �������
	void printQueue();

};



