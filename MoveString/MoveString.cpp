#include <iostream>
#include <string>
#include <vector>
using namespace std;

void PrintVector(const vector<int>& v, string str) {
	cout << str << endl;
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << " ";
	//cout << "\n";
}
void MoveStrings(vector<string>& source, vector<string>& destination) {
	for (auto s : source) {
		cout << s << " " << s.size() << endl;
	}

	int N = source.size();
	int M = destination.size();

	for (int i = 0; i < N; i++)
		destination.push_back(source[i]);
	source.clear();
}

void Reverse(vector<int>& v) {
	int N = v.size();
	vector<int> temp;
	for (int i = 0; i < N; i++)
		temp.push_back(v[N - i - 1]);
	v = temp;
}

vector<int> Reversed(const vector<int>& v) {
	int N = v.size();
	vector<int> temp;
	for (int i = 0; i < N; i++)
		temp.push_back(v[N - i - 1]);
	return temp;
}

int main()
{

	vector<string> source = { "aa", "b", "c" };
	vector<string> destination = { "z" };

	MoveStrings(source, destination);

	cout << "Source: " << endl;
	for (int i = 0; i < source.size(); i++)
		cout << source[i] << " ";
	cout << " ---------" << endl;
	cout << "Destination: " << endl;
	for (int j = 0; j < destination.size(); j++)
		cout << destination[j] << " ";


}
