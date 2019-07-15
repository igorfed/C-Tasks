// Написать программу вычисления стоимости покупки с учётом скидки. 
// Скидка в X процентов предоставляется, если сумма покупки больше A рублей, в Y процентов - если сумма больше B рублей.
// В стандартном вводе содержится пять вещественных чисел, разделённых пробелом: 
//N, A, B, X, Y (A < B) - где N - исходная стоимость товара. Выведите стоимость покупки с учётом скидки.

#include <iostream>
using namespace std;
int main()
{
	//100 110 120 5 10	100
	//115 110 120 5 10	109.25
	//150 110 120 5 12.5	131.25
	double N; // product cost
	double A; // limit 1
	double B; // limit 2 (A < B)
	double X, Y; // discount procents
	cin >> N >> A >> B >> X >> Y;

	if (N > A) {
		if (N <= B) cout << N - N * X / 100 << endl;
		else cout << N - N * Y / 100 << endl;
	}
	else
		cout << N << endl;

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
