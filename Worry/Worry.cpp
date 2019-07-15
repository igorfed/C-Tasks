// Worry.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
using namespace std;
#include <string>
#include <algorithm>

void MakeWorry(vector<string>& queue) {
	int place;
	cin >> place;
	queue[place] = "WORRY";
}


int WorryCount(const vector<string>& queue) {
	auto  C = count(queue.begin(), queue.end(), "WORRY");
	if (C >= 0) C = C; //cout << "C" << C << "size " << queue.size() << endl;
	else C = 0;
	return C;

}

void AddQuiet(vector<string>& queue, int addKPeople) {
	for (int i = 0; i < addKPeople; i++) {
		queue.push_back("QUIET");
	}
}

void RemoveQuiet(vector<string>& queue, int removeKPeople) {
	for (int i = 0; i < -removeKPeople; i++) {
		queue.pop_back();
	}
}


void MakeQuiet(vector<string>& queue) {
	int place;
	cin >> place;
	queue[place] = "QUIET";
}

enum ChosenCommand { stWorry, stCOME, stWORRY_COUNT, stQUIET, stWRONG };
ChosenCommand hashit(const string& Command) {

	if (Command == "ADD") return stWorry;
	else if (Command == "NEXT") return stCOME;
	else if (Command == "DUMP") return stWORRY_COUNT;
	else if (Command == "QUIET") return stQUIET;
	else return stWRONG;
}


int main()
{



	string Command;
	vector<string> queue(0);
	int Q;
	//cout << "Enter Q operations: ";
	cin >> Q;
	int quantity; // Number of people
	while (Q != 0) {
		//cout << "Enter operations: ";
		cin >> Command;

		switch (hashit(Command)) {
		case stWorry:
			MakeWorry(queue);
			break;
		case stCOME:
			cin >> quantity;
			if (quantity >= 0) AddQuiet(queue, quantity);
			else if (quantity < 0) RemoveQuiet(queue, quantity);
			//cout << queue.size() <<endl;
			break;
		case stWORRY_COUNT:
			cout << WorryCount(queue) << endl;
			break;
		case stQUIET:
			MakeQuiet(queue);
			break;
		default:
			//cout << "Invalid Command" << endl;
			break;
		}
		//cout << queue.size() << endl;
		--Q;


	}
}
//while (true) {
/*		// Введите команду
		cin >> command;
		if (command == "COME" && quantity > 0) {
			AddQuiet(queue, quantity);

	*///}







	// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
	// Debug program: F5 or Debug > Start Debugging menu

	// Tips for Getting Started: 
	//   1. Use the Solution Explorer window to add/manage files
	//   2. Use the Team Explorer window to connect to source control
	//   3. Use the Output window to see build output and other messages
	//   4. Use the Error List window to view errors
	//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
	//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
