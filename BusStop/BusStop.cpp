#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

void All_buses(const map<string, vector<string>>& f) { //вывод всех маршрутов
	if (f.size() == 0) cout << "No buses" << endl; //если размер контейнера = 0, то напишем что ничего нет
	else { //если что-то есть
		for (const auto& i : f) { //пролистаем контейнер и напишем, для каждой пары "ключ-значение"
			cout << "Bus " << i.first << ":"; //название маршрута
			for (const auto& d : i.second) { //а также перечислим 
				cout << " " << d; // название остановок
			}
			cout << endl;
		}
	}
}

void BusforStop(const map<string, vector<string>>& bsmap, const vector<string>& busm) {
	int k = 0; 
	string stop;
	cin >> stop;
	vector<string> v;
	for (const auto& i : bsmap) {
		for (const auto& n : i.second) { 
			if (n == stop) {  
				v.push_back(i.first); 
				k++; 
			}
		}
	}
	if (k > 0) { 
		for (const auto& w : busm) { 
			for (auto z : v) {  
				if (z == w) { 
					cout << w << " "; 
				} //таким образом у нас будут выведены маршруты в порядке записи командой NEW_BUS
			}
		}
	}
	else if (k == 0) cout << "No stop"; //если не нашли совпадение, то так и напишем
	cout << endl;
}
void Stopforbus(const map<string, vector<string>>& bsmap, const vector<string>& busm) {
	int l = 0; //переменная для определения наличия нужного маршрута
	string bus;
	cin >> bus;
	for (auto i : bsmap) { //просматриваем контейнер
		if (i.first == bus) { //если значение ключа совпало с названием маршрута
			for (auto m : i.second) { // (п.1) то для каждого значения этого ключа
				cout << "Stop " << m << ":"; //пишем остановку
				int l2 = 0; //переменная для определения наличия других маршрутов остановки, кроме первоначального
				vector<string> v;
				for (auto r : bsmap) { //снова пролистываем контейнер
					for (auto n : r.second) { //просматриваем все значения остановок
						//и если значение остановки совпало со значением ключа m в п.1, но не равно "введенному" маршруту s
						if (n == m && r.first != bus) {
							v.push_back(r.first); //запишем маршруты в вектор
							l2++;
						}
					}
				}
				if (l2 == 0) cout << " no interchange";
				else if (l2 > 0) {
					for (const auto& w : busm) { //пролистаем общий вектор с маршрутами и для каждого маршрута
						for (auto z : v) { //будем просматривать вектор "найденных" маршрутов 
							if (z == w) { //и при совпадении
								cout << " " << w; //выводим маршрут
							} //таким образом у нас будут выведены маршруты в порядке записи командой NEW_BUS
						}
					}
				}
				cout << endl; //с новой строки
			}
			l++; //если маршрут нашелся, то плюсуем
		}
	}
	if (l == 0) cout << "No bus" << endl; // если не нашлось маршрутов - так и пишем
}

void NEW_BUS(vector<string>& busm, map<string, vector<string>>& bsmap) {
	string bus, stop;
	int num_stops;
	cin >> bus >> num_stops; 
	busm.push_back(bus);
	for (num_stops; num_stops > 0; num_stops--) {
		cin >> stop; 
		bsmap[bus].push_back(stop); 
	}
}
int main()
{
	int Q;
	cin >> Q; 
	map<string, vector<string>> bsmap; 
	vector<string> busm;
	for (Q; Q > 0; Q--) { 
		string comand; 
		cin >> comand; 
		if (comand == "NEW_BUS") NEW_BUS(busm, bsmap);
		
		else if (comand == "BUSES_FOR_STOP") BusforStop(bsmap, busm);
		
		else if (comand == "STOPS_FOR_BUS") Stopforbus(bsmap, busm);
		
		else if (comand == "ALL_BUSES") All_buses(bsmap);
	}
	return 0;
}