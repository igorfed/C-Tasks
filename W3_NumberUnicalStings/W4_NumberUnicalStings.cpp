#include <iostream>
using namespace std;
#include <set>
int main()
{
    set<string> setOfString;
	int Q;
	string str;
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		cin >> str;
		setOfString.insert(str);
	}
	cout << setOfString.size();
}
