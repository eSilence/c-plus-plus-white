#include<iostream>
#include<fstream>
#include <algorithm>  
#include<string>
#include<vector>
#include<map>

using namespace std;

/*� ���� ������ ��� ����� ����������� ������ ���������� ���������.

� ������, ��� ������� ��������, ��������� ������� �������� ���������, ����� ���� ������ ����� ����� (������� �������� � 1, ������� � 2 � �. �.), ���� ������� ����� ������������� ��������, �������� ������������� ����� ����� ���������.

������ ���������, ���������� ���� �� ����� ������������� ���������, ��������� ���������� (��. ������).

��������
� C++ ������ ������� ����� ���� �� ������ ����� ��� ������, �� � ������ ���������, ��������, vector.

������ �����
������� �������� ���������� �������� Q, ����� Q �������� ��������.

������ ������ ������������ ����� ������������� ���������� ��������� N, �� ������� ������� ���������� �������� N ��������� �������� ��������� ���������������� ��������. �������� ��������� ������� ���� �� ��������� ���� � �������� �������������.

������ ������
�������� ����� �� ������ ������ � ��������� ������.

���� ������� � ������ ������� ��������� ��� ����������, � ����� �� ��������������� ������ �������� Already exists for i, ��� i � ����� �������� � ����� ������� ���������. � ��������� ������ ����� �������� ��������� ������ ��������� ����� ����� i � ������� ��� � ������� New bus i.

������
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