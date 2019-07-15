#include <iostream>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

map<char, int> BuildCharCounters(string m) {
	map<char, int> counters;
	for (auto item : m) {
		++counters[item];
	}
	return counters;
}


int main()
{
	int q;
	cin >> q;
	for (int i = 0; i < q; i++) {
		string word1, word2;
		cin >> word1 >> word2;
		if (BuildCharCounters(word1) == BuildCharCounters(word2))

			cout << "YES" << endl;

		else
			cout << "NO" << endl;
	}
}
