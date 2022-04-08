#include<iostream>
#include<fstream>
#include <algorithm>  
#include<string>
#include<vector>
#include<map>

using namespace std;

/*���������� ������� �������� ���������� ���������. ��� ����� ������������ ��������� �������:

NEW_BUS bus stop_count stop1 stop2 ... � �������� ������� �������� � ��������� bus � stop_count ����������� � ���������� stop1, stop2, ...

BUSES_FOR_STOP stop � ������� �������� ���� ��������� ��������, ���������� ����� ��������� stop.

STOPS_FOR_BUS bus � ������� �������� ���� ��������� �������� bus �� ������� ���������, �� ������� ����� ��������� �� ������ �� ���������.

ALL_BUSES � ������� ������ ���� ��������� � �����������.

������ �����
� ������ ������ ����� ���������� ���������� �������� Q, ����� � Q ������� ������� �������� ��������.

�������������, ��� ��� �������� ��������� � ��������� ������� ���� �� ��������� ����, ���� � ������ �������������.

��� ������� ������� NEW_BUS bus stop_count stop1 stop2 ... �������������, ��� ������� bus �����������, ���������� ��������� ������ 0, � ����� ����� stop_count ������� ������ ����� ���������� �������� ���������, ������ ��� �������� � ������ ������ ��������.

������ ������
��� ������� �������, ����� NEW_BUS, �������� ��������������� ����� �� ����:

�� ������ BUSES_FOR_STOP stop �������� ����� ������ ������ ���������, ����������� ����� ��� ���������, � ��� �������, � ������� ��� ����������� ��������� NEW_BUS. ���� ��������� stop �� ����������, �������� No stop.

�� ������ STOPS_FOR_BUS bus �������� �������� ��������� �������� bus � ��������� ������� � ��� �������, � ������� ��� ���� ������ � ��������������� ������� NEW_BUS. �������� ������ ��������� stop ������ ����� ��� Stop stop: bus1 bus2 ..., ��� bus1 bus2 ... � ������ ���������, ����������� ����� ��������� stop, � �������, � ������� ��� ����������� ��������� NEW_BUS, �� ����������� ��������� �������� bus. ���� ����� ��������� stop �� ��������� �� ���� �������, ����� bus, ������ ������ ��������� ��� �� �������� no interchange. ���� ������� bus �� ����������, �������� No bus.

�� ������ ALL_BUSES �������� �������� ���� ��������� � ���������� �������. �������� ������� �������� bus ������ ����� ��� Bus bus: stop1 stop2 ..., ��� stop1 stop2 ... � ������ ��������� �������� bus � �������, � ������� ��� ���� ������ � ��������������� ������� NEW_BUS. ���� �������� �����������, �������� No buses.
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

void NEW_BUS(map <string, vector<string>>& b, vector<string> &hist, string bus, int stop_count, vector<string> stops){// �������� ������� �������� � ��������� bus � stop_count ����������� � ���������� 
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

void BUSES_FOR_STOP(const map <string, vector<string>> &b, const vector<string> &hist, string stop) { // ������� �������� ���� ��������� ��������, ���������� ����� ��������� stop.
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

void STOPS_FOR_BUS(const map <string, vector<string>>& b, const vector<string> &hist, string bus){ // ������� �������� ���� ��������� �������� bus �� ������� ���������, �� ������� ����� ��������� �� ������ �� ���������.
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


void ALL_BUSES(const map <string, vector<string>> & b){// ������� ������ ���� ��������� � �����������.
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




//   ������� ������


#include <iostream>
#include <string>
#include <map>
#include <vector>

using namespace std;

// ����� �� ������ BUSES_FOR_STOP
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

// ����� �� ������ STOPS_FOR_BUS
void PrintStopsForBus(map<string, vector<string>>& buses_to_stops,
                      map<string, vector<string>>& stops_to_buses,
                      const string& bus) {
  if (buses_to_stops.count(bus) == 0) {
    cout << "No bus" << endl;
  } else {
    for (const string& stop : buses_to_stops[bus]) {
      cout << "Stop " << stop << ": ";
      
      // ���� ����� ��������� �������� ����� ���� �������,
      // �� ��� ��� ������� bus, �������������, ��������� ��� ���
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

// ����� �� ������ ALL_BUSES
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
      
      // � ������� ������ ����� �������� �������� �������
      // �� ������� ��������� ������� ��������;
      // ���� bus ���������� ������������ � �������, ������� �� �������������
      // ��������� ���� � ������ �������� � �������� ��������
      vector<string>& stops = buses_to_stops[bus];
      stops.resize(stop_count);
      
      for (string& stop : stops) {
        cin >> stop;
        // �� ������� �������� ������� stops_to_buses
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
