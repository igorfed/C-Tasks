#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

enum ChosenCommand { stADD, stNEXT, stDUMP, stWRONG };
ChosenCommand hashit(const string& Command) {
	if (Command == "ADD") return stADD;
	else if (Command == "NEXT") return stNEXT;
	else if (Command == "DUMP") return stDUMP;
	else return stWRONG;
}
void AddDoing(vector<vector<string>>& day) {
	int i;
	string s;
	cin >> i >> s;
	day[i - 1].push_back(s);
}

void COutDump(vector<vector<string>>& day) {
	int i;
	cin >> i;
	int S = day[i - 1].size();
	if (S > 0) {
		cout << S << ' ';
		for (auto j : day[i - 1]) cout << j << ' ';
		cout << '\n';
	}
	else cout << 0 << endl;
}


void NEXTMounth(const vector <int> Mounth, vector<vector<string>>& day, int& n, int& n1) {
	n1 = n;
	++n;
	if (n == 12) n = 0;
	if (Mounth[n] > Mounth[n1]) {
		day.resize(Mounth[n]);
	}
	if (Mounth[n] < Mounth[n1]) {
		for (int h = 0; h < (Mounth[n1] - Mounth[n]); h++) 
			day[Mounth[n] - 1].insert(end(day[Mounth[n] - 1]), begin(day[Mounth[n1] - 1 - h]), end(day[Mounth[n1] - 1 - h]));
		
		day.resize(Mounth[n]);
	}
}

int main()
{
	// 1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12
	vector <int> Mounth = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int q;
	int n = 0, n1 = 0;
	cin >> q; // Enter number of operations
	vector<string> doing;
	string doing_code;

	vector<vector<string>> day(31);
	for (int i = 0; i < q; ++i) {
		cin >> doing_code;

		switch (hashit(doing_code)) {
		case stADD:
			AddDoing(day);
			break;
		case stNEXT:
			NEXTMounth(Mounth, day, n, n1);
			break;
		case stDUMP:
			COutDump(day);
			break;
		default:

			break;
		}




	}

}


