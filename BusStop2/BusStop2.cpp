#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int main() {
	int Q, i;
	string stop;
	map<vector<string>, int> bs;
	cin >> Q; 
	for (Q; Q > 0; Q--) {
		vector<string> v;
		cin >> i;
		for (int z = 0; z < i; z++) {
			cin >> stop;
			v.push_back(stop);
		}
		if (bs.count(v)) {
			cout << "Already exists for " << bs[v] << endl;
		}
		else {
			bs[v];
			int r = bs.size();
			bs[v] = r;
			cout << "New bus " << bs[v] << endl;
		}
	}
	return 0;
}