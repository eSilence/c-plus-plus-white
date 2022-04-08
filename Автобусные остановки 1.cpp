#include<iostream>
#include<fstream>
#include <algorithm>  
#include<string>
#include<vector>
#include<map>

using namespace std;

/*Реализуйте систему хранения автобусных маршрутов. Вам нужно обрабатывать следующие запросы:

NEW_BUS bus stop_count stop1 stop2 ... — добавить маршрут автобуса с названием bus и stop_count остановками с названиями stop1, stop2, ...

BUSES_FOR_STOP stop — вывести названия всех маршрутов автобуса, проходящих через остановку stop.

STOPS_FOR_BUS bus — вывести названия всех остановок маршрута bus со списком автобусов, на которые можно пересесть на каждой из остановок.

ALL_BUSES — вывести список всех маршрутов с остановками.

Формат ввода
В первой строке ввода содержится количество запросов Q, затем в Q строках следуют описания запросов.

Гарантируется, что все названия маршрутов и остановок состоят лишь из латинских букв, цифр и знаков подчёркивания.

Для каждого запроса NEW_BUS bus stop_count stop1 stop2 ... гарантируется, что маршрут bus отсутствует, количество остановок больше 0, а после числа stop_count следует именно такое количество названий остановок, причём все названия в каждом списке различны.

Формат вывода
Для каждого запроса, кроме NEW_BUS, выведите соответствующий ответ на него:

На запрос BUSES_FOR_STOP stop выведите через пробел список автобусов, проезжающих через эту остановку, в том порядке, в котором они создавались командами NEW_BUS. Если остановка stop не существует, выведите No stop.

На запрос STOPS_FOR_BUS bus выведите описания остановок маршрута bus в отдельных строках в том порядке, в котором они были заданы в соответствующей команде NEW_BUS. Описание каждой остановки stop должно иметь вид Stop stop: bus1 bus2 ..., где bus1 bus2 ... — список автобусов, проезжающих через остановку stop, в порядке, в котором они создавались командами NEW_BUS, за исключением исходного маршрута bus. Если через остановку stop не проезжает ни один автобус, кроме bus, вместо списка автобусов для неё выведите no interchange. Если маршрут bus не существует, выведите No bus.

На запрос ALL_BUSES выведите описания всех автобусов в алфавитном порядке. Описание каждого маршрута bus должно иметь вид Bus bus: stop1 stop2 ..., где stop1 stop2 ... — список остановок автобуса bus в порядке, в котором они были заданы в соответствующей команде NEW_BUS. Если автобусы отсутствуют, выведите No buses.
10
ALL_BUSES
BUSES_FOR_STOP Marushkino
STOPS_FOR_BUS 32K
NEW_BUS 32 3 Tolstopaltsevo Marushkino Vnukovo
NEW_BUS 32K 6 Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
BUSES_FOR_STOP Vnukovo
NEW_BUS 950 6 Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
NEW_BUS 272 4 Vnukovo Moskovsky Rumyantsevo Troparyovo
STOPS_FOR_BUS 272
ALL_BUSES

output:
No buses
No stop
No bus
32 32K
Stop Vnukovo: 32 32K 950
Stop Moskovsky: no interchange
Stop Rumyantsevo: no interchange
Stop Troparyovo: 950
Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo
Bus 32: Tolstopaltsevo Marushkino Vnukovo
Bus 32K: Tolstopaltsevo Marushkino Vnukovo Peredelkino Solntsevo Skolkovo
Bus 950: Kokoshkino Marushkino Vnukovo Peredelkino Solntsevo Troparyovo
*/

void NEW_BUS(map <string, vector<string>>& b, vector<string> &hist, string bus, int stop_count, vector<string> stops){// добавить маршрут автобуса с названием bus и stop_count остановками с названиями 
	b[bus] = stops;
	hist.push_back(bus);
}

vector <string> find_BUSES_FOR_STOP(const map <string, vector<string>> &b, const vector<string> &hist, string stop){
	vector <string> res;
	for (string s: hist)
		if (count (b.at(s).begin(), b.at(s).end(), stop) != 0)
			res.push_back(s);
	
	return res;
}

void BUSES_FOR_STOP(const map <string, vector<string>> &b, const vector<string> &hist, string stop) { // вывести названия всех маршрутов автобуса, проходящих через остановку stop.
	//32 32K
	vector <string> res = find_BUSES_FOR_STOP(b, hist, stop);
	if (res.size() == 0)
		cout<< "No stop"<<endl;
	else {
		for (auto s: res)
			cout<<s<<" ";
		cout<<endl;
	}
	
}

void STOPS_FOR_BUS(const map <string, vector<string>>& b, const vector<string> &hist, string bus){ // вывести названия всех остановок маршрута bus со списком автобусов, на которые можно пересесть на каждой из остановок.
	//Stop Vnukovo: 32 32K 950
	if (b.count(bus) > 0) {
		vector<string> fs = b.at(bus);
		for (string s: fs){
			cout <<"Stop " << s <<": ";
			vector <string> res = find_BUSES_FOR_STOP(b, hist, s);
			res.erase(find(res.begin(),res.end(), bus));
			for (auto s: res)
				cout<<s<<" ";
			if (res.size() == 0)
				cout<< "no interchange";
			cout<<endl;
		}
	}
	else
		cout<< "No bus"<<endl;
}


void ALL_BUSES(const map <string, vector<string>> & b){// вывести список всех маршрутов с остановками.
	if (b.size() != 0)
		//Bus 272: Vnukovo Moskovsky Rumyantsevo Troparyovo
		for (pair<string, vector<string>> p: b){
			cout << "Bus "<< p.first<<": ";
			for (auto s: p.second)
				cout << s << " ";
			cout<<endl;
		}
	else
		cout<<"No buses"<<endl;
}

int main(){
	//ifstream f("com_3.txt", ios::in);
	map <string, vector<string>> buses;
	vector<string> hist;
	int n; cin>>n; 
	//f >> n;
	for (int i = 0; i < n; i++){
		string s; cin >> s; 
		//f >> s;
		if (s == "NEW_BUS"){ 
			string bus;
			int n;
			vector<string> vec;
			cin>>bus>>n;
			//f>>bus>>n;
			for(int i = 0; i < n; i++){
				string stop;
				cin >> stop;
				//f >> stop;
				vec.push_back(stop);
			}
			NEW_BUS(buses, hist, bus, n, vec);
		}
		else if (s == "STOPS_FOR_BUS") {
			string num; cin>>num;
			//f>>num;
			STOPS_FOR_BUS(buses, hist, num); 
		}
		else if(s=="BUSES_FOR_STOP"){
			string s; cin>>s;
			//f >> s;
			BUSES_FOR_STOP(buses, hist, s);
		}
		else if (s == "ALL_BUSES")
			ALL_BUSES(buses);
	}

	return 1;
}




//   решение автора


#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// ответ на запрос BUSES_FOR_STOP
void PrintBusesForStop(map<string, vector<string>>& stops_to_buses,
                       const string& stop) {
  if (stops_to_buses.count(stop) == 0) {
    cout << "No stop" << endl;
  } else {
    for (const string& bus : stops_to_buses[stop]) {
      cout << bus << " ";
    }
    cout << endl;
  }                
}

// ответ на запрос STOPS_FOR_BUS
void PrintStopsForBus(map<string, vector<string>>& buses_to_stops,
                      map<string, vector<string>>& stops_to_buses,
                      const string& bus) {
  if (buses_to_stops.count(bus) == 0) {
    cout << "No bus" << endl;
  } else {
    for (const string& stop : buses_to_stops[bus]) {
      cout << "Stop " << stop << ": ";
      
      // если через остановку проходит ровно один автобус,
      // то это наш автобус bus, следовательно, пересадки тут нет
      if (stops_to_buses[stop].size() == 1) {
        cout << "no interchange";
      } else {
        for (const string& other_bus : stops_to_buses[stop]) {
          if (bus != other_bus) {
            cout << other_bus << " ";
          }
        }
      }
      cout << endl;
    }
  }             
}

// ответ на запрос ALL_BUSES
void PrintAllBuses(const map<string, vector<string>>& buses_to_stops) {
  if (buses_to_stops.empty()) {
    cout << "No buses" << endl;
  } else {
    for (const auto& bus_item : buses_to_stops) {
      cout << "Bus " << bus_item.first << ": ";
      for (const string& stop : bus_item.second) {
        cout << stop << " ";
      }
      cout << endl;
    }
  }             
}

int main() {
  int q;
  cin >> q;

  map<string, vector<string>> buses_to_stops, stops_to_buses;

  for (int i = 0; i < q; ++i) {
    string operation_code;
    cin >> operation_code;

    if (operation_code == "NEW_BUS") {

      string bus;
      cin >> bus;
      int stop_count;
      cin >> stop_count;
      
      // с помощью ссылки дадим короткое название вектору
      // со списком остановок данного автобуса;
      // ключ bus изначально отсутствовал в словаре, поэтому он автоматически
      // добавится туда с пустым вектором в качестве значения
      vector<string>& stops = buses_to_stops[bus];
      stops.resize(stop_count);
      
      for (string& stop : stops) {
        cin >> stop;
        // не забудем обновить словарь stops_to_buses
        stops_to_buses[stop].push_back(bus);
      }

    } else if (operation_code == "BUSES_FOR_STOP") {

      string stop;
      cin >> stop;
      PrintBusesForStop(stops_to_buses, stop);

    } else if (operation_code == "STOPS_FOR_BUS") {

      string bus;
      cin >> bus;
      PrintStopsForBus(buses_to_stops, stops_to_buses, bus);

    } else if (operation_code == "ALL_BUSES") {

      PrintAllBuses(buses_to_stops);

    }
  }

  return 0;
}
