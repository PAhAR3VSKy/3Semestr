#pragma once
#include <iostream>
class Polynomial
{
public:
	Polynomial();
	Polynomial(int degree);//конструктор с параметрами
	Polynomial(const Polynomial &); //копирования
	~Polynomial();//деструктор
	int getDegree(); //функция получения степени полинома 
	double getCoefficientf(int); //функция получения коэффициента при i-й степени
	bool palindrome();		//проверка на палиндром
	Polynomial operator+(const Polynomial &);   //оператор сложения двух полиномов
	Polynomial operator-(const Polynomial &);   //оператор вычитания двух полиномов
	Polynomial operator*(const Polynomial &);   // оператор умножения
	Polynomial operator/(const Polynomial &);   // оператор деления
	void operator<(const Polynomial &);	// оператор сравнения
	friend std::ostream &operator<< (std::ostream &, const Polynomial &); // перегруженный оператор вывода
	friend std::istream &operator >> (std::istream &s, Polynomial &c); // перегруженный оператор ввода
private:
	int degree; //степень полинома
	double *coefficient; //указатель на массив коэффициентов полинома coefficient[i] - коэффициент при i-й степени
};

