// MiddleTemp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
vector <int> EnterTemp() {
	int N = 5;
	int K;
	cin >> N;
	vector <int> d;
	for (int i = 0; i < N; i++) {
		cin >> K;
		//cout << K << " ";
		d.push_back(K);
	}
	return d;
}


void MiddleTemp(vector<int>& d) {
	double sum = 0;
	int k = 0;
	int S = d.size();
	vector <int> m;
	if (S != 0) {
		//cout << "Size: " << S<< endl;
		for (int i = 0; i < S; i++) {
			sum += d[i];
		}
		sum /= S;
		for (int j = 0; j < S; j++) {
			//cout << d[j] << " : " ;
			if (sum < d[j]) {

				m.push_back(j);
				//
						//cout << k << " " << sum << " "<< m[k] <<" "<< d[j]<< endl;
				k += 1;
			}
		}
		//cout << k << endl;
	}
	else m.clear();

	cout << k << endl;
	for (int n = 0; n < k; n++) {
		cout << m[n] << " ";
	}

}



int main()
{

	vector<int> d;//= { 7, 6, 3, 0, 9};
	d = EnterTemp();
	MiddleTemp(d);

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
