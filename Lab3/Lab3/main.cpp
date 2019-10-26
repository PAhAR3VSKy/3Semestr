#include <iostream>
#include "Polynomial.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");

	int n, m;
	cout << "Введите степень полинома A и степень полинома B:" << '\n';
	cin >> n >> m;

	Polynomial A(n), B(m), Residue;
	cout << "Введите коэффициенты полинома A:" << '\n';
	cin >> A;
	cout << "Введите коэффициенты полинома B:" << '\n';
	cin >> B;
	cout << " Многочлен А: " << A << '\n';
	cout << " Многочлен B: " << B << '\n';
	cout << " Многочлен D=A+B: " << (A + B) << '\n';
	cout << " Многочлен K=A-B: " << (A - B) << '\n';
	cout << " Многочлен Y=A*B: " << (A * B) << '\n';
	cout << " Многочлен Y=A/B: " << (A / B) << '\n';
	(A < B);
	cout << endl;
	if (A.palindrome())
		cout << " Множество " << A << " является палиндромом!" << endl;
	else
		cout << endl << " Множество " << A << " неявляется палиндромом!" << endl;
	if (B.palindrome())
		cout << endl << " Множество " << B << " является палиндромом!" << endl;
	else
		cout << endl <<" Множество " << B << " неявляется палиндромом!" << endl;
	system("pause");
	return 0;
}