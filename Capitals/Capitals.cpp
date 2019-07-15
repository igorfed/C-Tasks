#include <iostream>
#include <vector>
#include <map>
using namespace std;
void PrintMaps(const map <string, string> Countries) {
	for (auto i : Countries) {
		cout << i.first << "/" << i.second << " ";
	}
	cout << endl;
}

int main()
{
	int q;
	cin >> q;

	map<string, string> Countries;
	string country, about_country;
	string new_capital, old_capital;
	string old_country_name, new_country_name;

	for (int i = 0; i < q; ++i) {
		string operation_code;
		cin >> operation_code;
		if (operation_code == "CHANGE_CAPITAL") {
			cin >> country >> new_capital;
			if (Countries.count(country) == 0) {
				cout << "Introduce new country " << country << " with capital " << new_capital << endl;
				Countries[country] = new_capital;
				//old_country_name = country;
			}
			else
				if (Countries.count(country) > 0)
					if (Countries[country] == new_capital)
						cout << "Country " << country << " hasn't changed its capital" << endl;
					else
					{
						cout << "Country " << country << " has changed its capital from " << Countries[country] << " to " << new_capital << endl;
						Countries[country] = new_capital;
					}
		}
		else if (operation_code == "RENAME") {
			cin >> old_country_name >> new_country_name;
			if ((Countries.count(old_country_name) == 0) || (old_country_name == new_country_name) || (Countries.count(new_country_name) != 0))
				cout << "Incorrect rename, skip" << endl;
			else
			{
				cout << "Country " << old_country_name << " with capital " << Countries[old_country_name] << " has been renamed to " << new_country_name << endl;

				Countries[new_country_name] = Countries[old_country_name];
				Countries.erase(old_country_name);
			}
		}
		else if (operation_code == "ABOUT") {
			cin >> about_country;
			if (Countries.count(about_country) == 0)
				cout << "Country " << about_country << " doesn't exist" << endl;
			else
				cout << "Country " << about_country << " has capital " << Countries[about_country] << endl;
		}
		else if (operation_code == "DUMP")
			if (Countries.empty())
				cout << "There are no countries in the world" << endl;
			else PrintMaps(Countries);
		//PrintMaps(Countries);
	}
}
