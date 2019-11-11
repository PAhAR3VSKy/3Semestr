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
    Polynomial(int);                            //конструктор с параметрами
    Polynomial(const Polynomial &);             //копирования
    ~Polynomial();                              //деструктор
    void setDegree(int);
    void setCoefficientf(int, double);
    void StringToDouble(QString);
    int getDegree();                            //функция получения степени полинома
    double getCoefficientf(int);                //функция получения коэффициента при i-й степени
    QString palindrome();                          //проверка на палиндром
    Polynomial operator+(const Polynomial &);   // оператор сложения двух полиномов
    Polynomial operator-(const Polynomial &);   // оператор вычитания двух полиномов
    Polynomial operator*(const Polynomial &);   // оператор умножения
    Polynomial operator/(const Polynomial &);   // оператор деления
    Polynomial operator%(const Polynomial &);   // оператор остатка от деления
    QString show();                             //  функция вывода
    QString operator<( Polynomial &);         // оператор сравнения
private:
    int degree;                                 //степень полинома
    double *coefficient;                        //указатель на массив коэффициентов полинома coefficient[i] - коэффициент при i-й степени
};

