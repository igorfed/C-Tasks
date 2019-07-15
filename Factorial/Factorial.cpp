// FActorial.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
#include <string>
#include <vector>

int Factorial(int x) {

	if (x > 0) {
		int F = x;
		for (int i = 1; i < x; i++) F = F * i;
		return F;
	}
	else
		return 1;
}

bool IsPalindrom(string str) {

	int N = str.size();
	bool f;
	if (str.empty() || N == 1) return true;
	else {
		for (size_t i = 0; i < N / 2; i++) {
			//cout << i << endl;
			//cout << i << ":" << str[i] << " " << N - i - 1 << ":" << str[N - i - 1] << endl;
			if (str[i] == str[N - i - 1]) f = true;
			else return false;
		}
		return f;
	}
}

vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> str;
	for (auto i : words) {
		if ((i.size() >= minLength) && (IsPalindrom(i) == true)) {
			str.push_back(i);
		}
	}

	return str;
}

int main()
{
	string str;
	//vector<string> words = { "abacaba" , "aba"};
	//vector<string> words = { "abacaba" , "aba" };
	vector<string> words = { "weew", "bro", "code" };

	vector<string> S;

	int minLength;
	cin >> minLength;
	S = PalindromFilter(words, minLength);

	for (size_t i = 0; i < S.size(); i++) {
		cout << S[i] << endl;
	}
	//S = PalindromFilter(words, minLength);

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
