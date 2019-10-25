#pragma once
#include <iostream>
class Polynomial
{
public:
	Polynomial();
	Polynomial(int degree);//����������� � �����������
	Polynomial(const Polynomial &); //�����������
	~Polynomial();//����������
	int getDegree(); //������� ��������� ������� �������� 
	double getCoefficientf(int); //������� ��������� ������������ ��� i-� �������
	Polynomial operator+(const Polynomial &);   //�������� �������� ���� ���������
	Polynomial operator-(const Polynomial &);   //�������� ��������� ���� ���������
	Polynomial operator*(const Polynomial &);   // �������� ���������
	Polynomial operator/(const Polynomial &);   // �������� �������
	friend std::ostream &operator<< (std::ostream &, const Polynomial &); // ������������� �������� ������
	friend std::istream &operator >> (std::istream &s, Polynomial &c); // ������������� �������� �����
private:
	int degree; //������� ��������
	double *coefficient; //��������� �� ������ ������������� �������� coefficient[i] - ����������� ��� i-� �������
};

