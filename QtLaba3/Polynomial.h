#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H


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
    void setCoefficientf(int, double);
    int getDegree();                            //функция получения степени полинома
    double getCoefficientf(int);                //функция получения коэффициента при i-й степени
    QString palindrome();                          //проверка на палиндром
    Polynomial operator+(const Polynomial &);   // оператор сложения двух полиномов
    Polynomial operator-(const Polynomial &);   // оператор вычитания двух полиномов
    Polynomial operator*(const Polynomial &);   // оператор умножения
    Polynomial operator/(const Polynomial &);   // оператор деления
    Polynomial operator%(const Polynomial &);   // оператор остатка от деления
    Polynomial operator=(const Polynomial &);   // оператор присваивания
    QString show();                             //  функция вывода
    QString operator<( Polynomial &);           // оператор сравнения
private:
    int degree;                                 //степень полинома
    double *coefficient;                        //указатель на массив коэффициентов полинома coefficient[i] - коэффициент при i-й степени
};

#endif // POLYNOMIAL_H
