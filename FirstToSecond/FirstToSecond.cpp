#include <iostream>
using namespace std;
void UpdateIfGreater(int a, int& b) {
	if (a > b) b = a;
}
int main()
{
	int a = 2;
	int b = 4;
	UpdateIfGreater(a, b);
	cout << a << " " << b << endl;
}
