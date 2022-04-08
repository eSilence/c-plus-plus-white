#include<iostream>
#include<fstream>
#include <algorithm>  
#include<string>
#include<vector>
#include<map>
#include<set>

using namespace std;  //set

/*В этой задаче вам нужно присваивать номера автобусным маршрутам.

А именно, для каждого маршрута, заданного множеством названий остановок, нужно либо выдать новый номер (первому маршруту — 1, второму — 2 и т. д.), либо вернуть номер существующего маршрута, которому соответствует такое множество остановок.

В отличие от задачи «Автобусные остановки — 2», наборы остановок, которые можно получить друг из друга перестановкой элементов или добавлением/удалением повторяющихся, следует считать одинаковыми.  

Формат ввода
Сначала вводится количество запросов Q, затем Q описаний запросов.

Каждый запрос представляет собой положительное количество остановок N, за которым следуют разделённые пробелом N названий остановок соответствующего маршрута (не обязательно различных). Названия остановок состоят лишь из латинских букв и символов подчёркивания.

Формат вывода
Выведите ответ на каждый запрос в отдельной строке.

Если маршрут с данным набором остановок уже существует, в ответ на соответствующий запрос выведите Already exists for i, где i — номер маршрута с таким набором остановок. В противном случае нужно выделить введённому набору остановок новый номер i и вывести его в формате New bus i.

Пример
Ввод

5
2 Marushkino Kokoshkino
1 Kokoshkino
2 Marushkino Kokoshkino
2 Kokoshkino Marushkino
2 Kokoshkino Kokoshkino

output:
New bus 1
New bus 2
Already exists for 1
Already exists for 1
Already exists for 2

*/


int main(){
	ifstream f("com_3.txt", ios::in);
	
	map <set<string>, int> buses;

	int n; cin>>n; 
	//f >> n;
	for (int i = 0; i < n; i++){
		int c; cin >> c; 
		//f >> c;
		set<string> stops;
		for (int j = 0; j < c; j++){
			string s; cin >> s; 
			//f >> s;
			stops.insert(s);
		}
		int num = buses.size()+1;
		if (buses.find(stops) == buses.end()){
			buses[stops] = num;
			cout<<"New bus "<< num << endl;
		}
		else
			cout<<"Already exists for " << buses[stops] << endl;
	}

	return 1;
}