#include "Polynomial.h"



Polynomial::Polynomial()
{
	coefficient = NULL;
}

Polynomial::Polynomial(int degree)
{
	int i;
	this->degree = degree;
	coefficient = new double[degree + 1];
	for (i = 0; i < degree; i++)
	{
		coefficient[i] = 0;
	}
}

Polynomial::Polynomial(const Polynomial &object)
{
	degree = object.degree;
	coefficient = new double[degree + 1];
	for (int i = 0; i < degree; i++)
	{
		coefficient[i] = object.coefficient[i];
	}
}




Polynomial::~Polynomial()
{
	delete[] coefficient;
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

Polynomial Polynomial::operator+(const Polynomial &object)
{
	int i;
	if (degree >= object.degree)
	{
		Polynomial New = *this;
		for (i = 0; i < degree; i++)
			New.coefficient[i] = coefficient[i] + object.coefficient[i];
		return New;
	}
	else
	{
		Polynomial New = object;
		for (i = 0; i < degree; i++)
			New.coefficient[i] = object.coefficient[i] + coefficient[i];
		return New;
	}
	return Polynomial();
}

Polynomial Polynomial::operator-(const Polynomial &object)
{
	int i;
	if (degree >= object.degree)
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
	return Polynomial();
}

Polynomial Polynomial::operator*(const Polynomial &object)
{
	int i, j, s = 0;
	Polynomial New = degree + object.degree;
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
		New.coefficient[New.degree - i - 1] = temp.coefficient[degree - i - 1] / object.coefficient[object.degree - 1];
		for (int j = 0; j < object.degree; j++)
		{
			temp.coefficient[degree - j - i - 1] -= object.coefficient[object.degree - j - 1] * New.coefficient[New.degree - i - 1];
		}

	}
	std::cout << " Остаток от деления: " << temp << std::endl;
	return New;

}


std::ostream & operator<<(std::ostream & object, const Polynomial & expression)
{
	int i, n = 0;
	for (i = 0; i < expression.degree; i++)
	{
		if (expression.coefficient[i] != 0)
			n++;
	}
	if (n != 0)
	{
		if (expression.coefficient[0] != 0)
		{
			object << expression.coefficient[0];
		}
		for (i = 1; i < expression.degree; i++)
		{
			if (expression.coefficient[i] < 0)
			{
				if (expression.coefficient[i] != -1)
					object << expression.coefficient[i] << "X^" << i;
				else
					object << "-" << "X^" << i;
			}
			else
			{
				if (expression.coefficient[i] != 0)
				{
					if (expression.coefficient[i] != 1)
						object << "+" << expression.coefficient[i] << "X^" << i;
					else
						object << "+" << "X^" << i;
				}
			}
		}
		object << '\n';
	}
	else
		object << 0;
	return object;
}

std::istream & operator>>(std::istream & object, Polynomial & expression)
{
	int i;
	for (i = 0; i < expression.degree; i++)
		object >> expression.coefficient[i];
	return object;
}

Polynomial::Polynomial()
{
}


Polynomial::~Polynomial()
{
}
