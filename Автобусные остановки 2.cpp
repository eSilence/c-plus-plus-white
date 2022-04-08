#include<iostream>
#include<fstream>
#include <algorithm>  
#include<string>
#include<vector>
#include<map>

using namespace std;

/*В этой задаче вам нужно присваивать номера автобусным маршрутам.

А именно, для каждого маршрута, заданного набором названий остановок, нужно либо выдать новый номер (первому маршруту — 1, второму — 2 и т. д.), либо вернуть номер существующего маршрута, которому соответствует такой набор остановок.

Наборы остановок, полученные друг из друга перестановкой остановок, считаются различными (см. пример).

Указание
В C++ ключом словаря может быть не только число или строка, но и другой контейнер, например, vector.

Формат ввода
Сначала вводится количество запросов Q, затем Q описаний запросов.

Каждый запрос представляет собой положительное количество остановок N, за которым следуют разделённые пробелом N различных названий остановок соответствующего маршрута. Названия остановок состоят лишь из латинских букв и символов подчёркивания.

Формат вывода
Выведите ответ на каждый запрос в отдельной строке.

Если маршрут с данным набором остановок уже существует, в ответ на соответствующий запрос выведите Already exists for i, где i — номер маршрута с таким набором остановок. В противном случае нужно выделить введённому набору остановок новый номер i и вывести его в формате New bus i.

Пример
4
2 Marushkino Kokoshkino
1 Kokoshkino
2 Marushkino Kokoshkino
2 Kokoshkino Marushkino

output:
New bus 1
New bus 2
Already exists for 1
New bus 3
*/


int main(){
	ifstream f("com_3.txt", ios::in);
	
	map <vector<string>, int> buses;

	int n; cin>>n; 
	//f >> n;
	for (int i = 0; i < n; i++){
		int c; cin >> c; 
		//f >> c;
		vector<string> stops;
		for (int j = 0; j < c; j++){
			string s; cin >> s; 
			//f >> s;
			stops.push_back(s);
		}
		int num = buses.size();
		if (buses.find(stops) == buses.end()){
			buses[stops] = num + 1;
			cout<<"New bus "<< num + 1 << endl;
		}
		else
			cout<<"Already exists for " << buses[stops] << endl;
	}

	return 1;
}