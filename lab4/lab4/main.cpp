#include <iostream>

using namespace std;

#include "queue.h" // подключаем шаблон класса

int main()
{
	QueueP<int> Q1;
	QueueP<int> Q2 = Q1;

	Q1.Push(15, 7);
	Q1.Push(18, 9);
	Q1.Push(18, 9);
	Q1.Push(18, 9);
	Q1.Push(1, 3);
	Q1.Push(8, 6);
	Q1.Push(11, 6);
	Q1.Push(4, 6);
	Q1.Print("Q1");

	int d;
	d = Q1.Pop();
	d = Q1.Pop();
	d = Q1.Pop();
	d = Q1.Pop();
	Q1.Print("Q1");
	cout << "d = " << d << endl;

	QueueP<int> Q3 = Q1; // конструктор копирования
	Q3.Print("Q3");

	QueueP<int> Q4;
	Q4 = Q3 = Q1; // оператор присваивания копированием
	Q4.Print("Q4");

	cout << "count = " << Q4.Count() << endl;
	Q4.Clear();
	Q4.Print("Q4");
	cout << "count = " << Q4.Count() << endl;
}