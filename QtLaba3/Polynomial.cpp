 #include "Polynomial.h"



Polynomial::Polynomial()
{
    degree = 0;
    coefficient = NULL; //полином равный 0
}

Polynomial::Polynomial(int degree)
{
    int i;
    this->degree = degree;
    coefficient = new double[degree + 1];
    for (i = 0; i < degree; i++) // выделение места под коэффициенты
    {
        coefficient[i] = 0;
    }
}

Polynomial::Polynomial(const Polynomial &object)
{
    degree = object.degree;
    coefficient = new double[degree + 1];
    for (int i = 0; i < degree; i++) // копирование объекта класса
    {
        coefficient[i] = object.coefficient[i];
    }
}




Polynomial::~Polynomial()
{
    delete[] coefficient;
}

void Polynomial::setDegree(int degree)
{
    this->degree = degree;
}

void Polynomial::setCoefficientf(int value, double count)
{
    this->coefficient[value] = count;
}

int Polynomial::getDegree()
{
    return degree;
}

double Polynomial::getCoefficientf(int number)
{
    if (number <= degree)
        return coefficient[number];
    else
        return 0.0;
}

QString Polynomial::palindrome()
{
    QString resultLine;
    bool result;
    for (int i = 0; i < degree; i++) // проверка множества на полиндром от 0 до n коэффициента
    {
        if (coefficient[i] != coefficient[degree - i - 1])
            result = false;
        else
            result = true;
    }
    if(result)
        resultLine = "Множество " + (this->show()) + " является палиндромом";
    else
        resultLine = "Множество " + (this->show()) + " не является палиндромом";
    return resultLine;
}

Polynomial Polynomial::operator+(const Polynomial &object)
{
    int i;
    if (degree >= object.degree) // сложение меньшего объекта с большим Пример: А + В
    {
        Polynomial New = *this;
        for (i = 0; i < degree; i++)
            New.coefficient[i] = coefficient[i] + object.coefficient[i];
        return New;
    }
    else // сложение меньшего объекта с большим Пример: В + А
    {
        Polynomial New = object;
        for (i = 0; i < degree; i++)
            New.coefficient[i] = object.coefficient[i] + coefficient[i];
        return New;
    }
}

Polynomial Polynomial::operator-(const Polynomial &object)
{
    int i;
    if (degree >= object.degree) // аналогично сложению
    {
        Polynomial New = *this;
        for (i = 0; i < degree; i++)
            New.coefficient[i] = coefficient[i] - object.coefficient[i];
        return New;
    }
    else
    {
        Polynomial New = object;
        for (i = 0; i < degree; i++)
            New.coefficient[i] = -object.coefficient[i] + coefficient[i];
        for (i = degree + 1; i < object.degree; i++)
            New.coefficient[i] = -object.coefficient[i];
        return New;
    }
}

Polynomial Polynomial::operator*(const Polynomial &object)
{
    int i, j;
    Polynomial New = degree + object.degree - 1;
    for (i = 0; i < degree; i++)
        for (j = 0; j < object.degree; j++)
            New.coefficient[i + j] += coefficient[i] * object.coefficient[j];
    return New;
}

Polynomial Polynomial::operator/(const Polynomial &object)
{
    Polynomial New = degree - object.degree + 1;
    Polynomial temp = *this;
    for (int i = 0; i < New.degree; i++)
    {
        New.coefficient[i] = (int)((abs)(temp.coefficient[i]) / (abs)(object.coefficient[0]));
        double q = New.coefficient[i];
        for (int j = 0; j < object.degree; j++)
        {
            temp.coefficient[j+i] -= (int)(object.coefficient[j] * New.coefficient[i]);
            double w = temp.coefficient[j+i];
        }

    }

    return New;

}

Polynomial Polynomial::operator%(const Polynomial &object)
{
    Polynomial temp = *this;
    Polynomial New = (temp/object);
    for (int i = 0; i < New.degree; i++)
    {
        for (int j = 0; j < object.degree; j++)
        {
            temp.coefficient[j+i] -= (int)(object.coefficient[j] * New.coefficient[i]);
        }

    }
    return temp;

}

QString Polynomial::operator<(Polynomial &object)
{
    int sumCoeffThis = 0;
    int sumCoeffObject = 0;
    QString resultLine;
    if (degree > object.degree)
        resultLine = " Множество " + (this->show()) + " больше!";
    else if (degree == object.degree)
    {
        for (int i = 0; i < degree; i++)
            sumCoeffThis += coefficient[i];
        for (int i = 0; i < object.degree; i++)
            sumCoeffObject += object.coefficient[i];
        if (sumCoeffThis < sumCoeffObject)
            resultLine = " Множество " + object.show() + " больше!";
        else if (sumCoeffThis == sumCoeffObject)
            resultLine = " Множества равны";
        else
            resultLine = " Множество " + (this->show()) + " больше!";
    }
    else
        resultLine = " Множество " + object.show() + " больше!";
    return resultLine;
}

QString Polynomial::show()
{
    Polynomial NewTemp = * this;
    QString NewString;
    int n = 0;
    for (int i = 0; i < NewTemp.degree; i++)
    {
        if(NewTemp.getCoefficientf(i) != 0)
            n++;
    }
    if(n != 0)
    {
        if (NewTemp.getCoefficientf(0) != 0)
        {
            if(NewTemp.getCoefficientf(0) != 1)
                NewString = QString::number(NewTemp.getCoefficientf(0)) + "X^" + QString::number(NewTemp.degree - 1);
            else
                NewString =  "X^" + QString::number(NewTemp.degree - 1);
        }
        for (int i = 1; i < NewTemp.degree; i++)
        {
            if (NewTemp.getCoefficientf(i) < 0)
            {
                if(NewTemp.degree - i - 1 == 0)
                {
                        NewString += QString::number(NewTemp.getCoefficientf(i));
                }
                else
                {
                    if (NewTemp.getCoefficientf(i) != -1)
                        NewString +=  QString::number(NewTemp.getCoefficientf(i)) + "X^" + QString::number(NewTemp.degree - i - 1);
                    else
                        NewString += "-X^" + QString::number(NewTemp.degree - i - 1);
                }

            }
            else
            { 
                if (NewTemp.getCoefficientf(i) != 0)
                {
                    if(NewTemp.getCoefficientf(i-1) == 0)
                    {
                        if(NewTemp.degree - i - 1 == 0)
                        {
                                NewString += QString::number(NewTemp.getCoefficientf(i));
                        }
                        else
                        {
                             if (NewTemp.getCoefficientf(i) != 1)
                                 NewString +=  QString::number(NewTemp.getCoefficientf(i)) + "X^" + QString::number(NewTemp.degree - i - 1);
                             else
                                 NewString += "X^"  + QString::number(NewTemp.degree - i - 1);
                        }
                    }
                    else
                    {
                        if(NewTemp.degree - i - 1 == 0)
                        {
                                NewString += '+' + QString::number(NewTemp.getCoefficientf(i));
                        }
                        else
                        {
                             if (NewTemp.getCoefficientf(i) != 1)
                                 NewString += '+' + QString::number(NewTemp.getCoefficientf(i)) + "X^" + QString::number(NewTemp.degree - i - 1);
                             else
                                 NewString += "+X^"  + QString::number(NewTemp.degree - i - 1);
                        }
                    }


                }
            }
        }
    }
    else
        NewString += "";
    return NewString;
}



