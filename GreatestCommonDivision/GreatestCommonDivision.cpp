// GreatestCommonDivision.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int main()
{
	//1. Bigger value div to smaller
	// Если меньшее делится без остатка то оно и есть НОД (проверка остаток равен 0 или нет)
	//Если есть остаток, то большее заменяем на остаток 
	int A, B, C;
	cin >> A >> B;
	//cout << "A = " << A << " B= " << B << endl;
	while (A != 0 && B != 0) {
		if (A > B) A = A % B;
		else if (A < B) B = B % A;
		else {
			A = A;
			B = 0;
		}
	}
	C = A + B; // A or B should be equal 0
	cout << C;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
