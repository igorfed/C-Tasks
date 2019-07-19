#include <iostream>
using namespace std;
#include <set>
#include <map>

void PrintSet(const set<string> & s) {
	for (auto x : s) cout << x << endl;
}

set<string> BuildMapValuesSet(const map <int, string>& m){
	set<string> str;
	for (const auto i : m) {
		//cout << i.first << " " << i.second << endl;
		str.insert(i.second);
	}
	return str;
}
int main()
{
	map <int, string> temp = {{ 1, "odd" }, { 2, "even" }, { 3, "odd" }, { 4, "even" }, { 5, "odd" }};

	set<string> values = BuildMapValuesSet(temp);
	PrintSet(values);
}

