#include <iostream>
#include "Polynomial.h"
#include<iomanip>

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
	cout << setw(17) << "��������� �:" << setw(5) << A << '\n';
	cout << setw(17) << "��������� B:" << setw(5) << B << '\n';
	cout << setw(17) << "��������� D=A+B:" << setw(5) << (A + B) << '\n';
	cout << setw(17) << "��������� K=A-B:" << setw(5) << (A - B) << '\n';
	cout << setw(17) << "��������� Y=A*B:" << setw(5) << (A * B) << '\n';
	cout << setw(17) << "��������� Y=A/B:" << setw(5) << (A / B) << '\n';
	/*cout << setw(17) << "������� �� ������� Y=A/B:" << setw(5) << A.residue() << '\n';*/
	system("pause");
	return 0;
}