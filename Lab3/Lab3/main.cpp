#include <iostream>
#include "Polynomial.h"
#include<iomanip>

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
	cout << setw(17) << "Многочлен А:" << setw(5) << A << '\n';
	cout << setw(17) << "Многочлен B:" << setw(5) << B << '\n';
	cout << setw(17) << "Многочлен D=A+B:" << setw(5) << (A + B) << '\n';
	cout << setw(17) << "Многочлен K=A-B:" << setw(5) << (A - B) << '\n';
	cout << setw(17) << "Многочлен Y=A*B:" << setw(5) << (A * B) << '\n';
	cout << setw(17) << "Многочлен Y=A/B:" << setw(5) << (A / B) << '\n';
	/*cout << setw(17) << "остаток от деления Y=A/B:" << setw(5) << A.residue() << '\n';*/
	system("pause");
	return 0;
}