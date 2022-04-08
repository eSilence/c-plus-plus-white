#include<iostream>
#include<fstream>
#include <algorithm>  
#include<string>
#include<vector>
#include<map>
#include<set>

using namespace std;  //set

/*� ���� ������ ��� ����� ����������� ������ ���������� ���������.

� ������, ��� ������� ��������, ��������� ���������� �������� ���������, ����� ���� ������ ����� ����� (������� �������� � 1, ������� � 2 � �. �.), ���� ������� ����� ������������� ��������, �������� ������������� ����� ��������� ���������.

� ������� �� ������ ����������� ��������� � 2�, ������ ���������, ������� ����� �������� ���� �� ����� ������������� ��������� ��� �����������/��������� �������������, ������� ������� �����������.  

������ �����
������� �������� ���������� �������� Q, ����� Q �������� ��������.

������ ������ ������������ ����� ������������� ���������� ��������� N, �� ������� ������� ���������� �������� N �������� ��������� ���������������� �������� (�� ����������� ���������). �������� ��������� ������� ���� �� ��������� ���� � �������� �������������.

������ ������
�������� ����� �� ������ ������ � ��������� ������.

���� ������� � ������ ������� ��������� ��� ����������, � ����� �� ��������������� ������ �������� Already exists for i, ��� i � ����� �������� � ����� ������� ���������. � ��������� ������ ����� �������� ��������� ������ ��������� ����� ����� i � ������� ��� � ������� New bus i.

������
����

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