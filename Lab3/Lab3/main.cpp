#include <iostream>
#include "Polynomial.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int n, m;
	cout << "������� ������� �������� A � ������� �������� B:" << '\n';
	cin >> n >> m;

	Polynomial A(n), B(m), Residue;
	cout << "������� ������������ �������� A:" << '\n';
	cin >> A;
	cout << "������� ������������ �������� B:" << '\n';
	cin >> B;
	cout << " ��������� �: " << A << '\n';
	cout << " ��������� B: " << B << '\n';
	cout << " ��������� D=A+B: " << (A + B) << '\n';
	cout << " ��������� K=A-B: " << (A - B) << '\n';
	cout << " ��������� Y=A*B: " << (A * B) << '\n';
	cout << " ��������� Y=A/B: " << (A / B) << '\n';
	(A < B);
	cout << endl;
	if (A.palindrome())
		cout << " ��������� " << A << " �������� �����������!" << endl;
	else
		cout << endl << " ��������� " << A << " ���������� �����������!" << endl;
	if (B.palindrome())
		cout << endl << " ��������� " << B << " �������� �����������!" << endl;
	else
		cout << endl <<" ��������� " << B << " ���������� �����������!" << endl;
	system("pause");
	return 0;
}