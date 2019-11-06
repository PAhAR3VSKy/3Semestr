#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#endif // POLYNOMIAL_H

#pragma once
#include <iostream>
#include <QString>
#include <QVariant>
#include <QMessageBox>
class Polynomial
{
public:
    Polynomial();
    Polynomial(int);//конструктор с параметрами
    Polynomial(const Polynomial &); //копирования
    ~Polynomial();//деструктор
    void setDegree(int);
    void setCoefficientf(int, double);
    void StringToDouble(QString);
    int getDegree(); //функция получения степени полинома
    double getCoefficientf(int); //функция получения коэффициента при i-й степени
    bool palindrome();		//проверка на палиндром
    Polynomial operator+(const Polynomial &);   //оператор сложения двух полиномов
    Polynomial operator-(const Polynomial &);   //оператор вычитания двух полиномов
    Polynomial operator*(const Polynomial &);   // оператор умножения
    Polynomial operator/(const Polynomial &);   // оператор деления
    QString show(QString);
    void operator<(const Polynomial &);	// оператор сравнения
    friend std::ostream &operator<< (std::ostream &, const Polynomial &); // перегруженный оператор вывода
    friend std::istream &operator >> (std::istream &s, Polynomial &c); // перегруженный оператор ввода
private:
    int degree; //степень полинома
    double *coefficient; //указатель на массив коэффициентов полинома coefficient[i] - коэффициент при i-й степени
};

