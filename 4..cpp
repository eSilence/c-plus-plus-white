#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

/*� ������� �� ��� ���� ������������� ����������� ����, ������ �� ������� ����� ��������� � ���������� ���� ������� ������: ������ ������ �� �������������, ����������� ����� �� ����� � ��. ��� ����� ����������� ������ �� ������� ����� ��� �� �����, � ������, ����������� ����� ��������� ��������:

ADD i s
��������� ���� � ��������� s �� ���� i �������� ������.

DUMP i
������� ��� ����, ��������������� �� ���� i �������� ������.

NEXT
������� � ������ ��� �� ����� �����. ��� ���������� ������ ������� ������ �������� (�������) ������ ��� �� ������� ����� �������� � ���������� �������� (�����) ������ ��� �� ��������� �����: ��� ���� �� ������� ������ ��� ���������� � ����� ������. ����� ���������� ������ ������� ����� ������ ��� � ��������� ����� ���������� ��������, � ������ �� ������ ������� ��� ������������.  ��� �������� � ������ ������ ���������� �������� �������� �� ������ ���������� ���� � �������:

���� ��������� ����� ����� ������ ����, ��� �������, ��������������� ��� ���������� �������� ������� (�� ����������� ���);

���� ��������� ����� ����� ������ ����, ��� �������, ���� �� ���� �������� ���� ���������� ����������� �� ��������� ���� ���������� ������.

���������
������� ������� ��� ������� �� ���������, ������ ������� ������ � ������� ������� ��� �������� ������. ����� ����, ��� �������� ������ ��� �� ��������� �����, �� ����������� ���������� ������.

�������� ��������, ��� ���������� ������ NEXT � ����� ������������������ ������ ��� ������ �� ������� ��� ����� ��������� 11.

��������� ������� ������� ��������� ������.

���������� ���� � ������� ������������� �������������� ��������� � ��� ���� ��������, ��� � ������� ������ 28 ����.

������ �����
������� ����� �������� Q, ����� �������� ��������.

�������� ��� s ��������� � ������� ������ �� ��������� ����, ���� � �������� �������������. ������ ���� i �������� ������ ������� � ���������� �� 1 �� ������� �������� ������.

������ ������
��� ������ �������� ���� DUMP � ��������� ������ �������� ���������� ��� � ��������������� ����, � ����� �� ��������, �������� �� ��������. ������� ������ ��� � ������ ������ �������� �������� �� �����.

������
12
ADD 5 Salary
ADD 31 Walk
ADD 30 WalkPreparations
NEXT
DUMP 5
DUMP 28
NEXT
DUMP 31
DUMP 30
DUMP 28
ADD 28 Payment
DUMP 28

output:
1 Salary
2 WalkPreparations Walk
0
0
2 WalkPreparations Walk
3 WalkPreparations Walk Payment

*/

void ADD(vector<vector<string>> &a, int i, string s){ //��������� ���� � ��������� s �� ���� i �������� ������.
	a[i].push_back(s);
}

void DUMP (const vector<vector<string>> &a, int i){ //������� ��� ����, ��������������� �� ���� i �������� ������.
	cout << a[i].size()<<" ";
	for (string s: a[i])
		cout << s <<" ";
	cout<<endl;
}

void DUMP_ALL (const vector<vector<string>> &a){ //������� ��� ���� �������� ������.
	cout<<"\ndays = "<< a.size()<<endl;
	for (int i = 0; i < a.size(); i++){
		if (a[i].size() > 0){
			cout << i<<": "<<a[i].size()<<" ";
			for (string s: a[i])
				cout << s <<" ";
			cout<<endl;
		}
	}
}

void NEXT(vector<vector<string>> &a, int mes){ //������� � ������ ��� �� ����� �����. 
	int days[] = {31, 28,31,30,31,30,31,31,30,31,30,31};
	if (a.size() > days[mes]){
		for (int i = days[mes] ; i < a.size(); i++)
			for (string s: a[i])
				a[days[mes]-1].push_back(s);
	}
		a.resize(days[mes]);
}

int main(){
	ifstream f("com_3.txt", ios::in);
	vector<vector<string>> a(31);
	int n; cin>>n; 
	//f >> n;
	int mes = 0;
	for (int i = 0; i < n; i++){
		string s;
		cin>>s; 
		//f >> s;
		if (s == "NEXT"){ 
			mes = (mes + 1)%12;
			NEXT(a, mes);
		}
		else{
			int t; cin>> t;
			//f >> t;
			if (s=="DUMP") DUMP(a, t-1);
			else if (s=="ADD") {
				string p; cin>> p;
				//f >> p;
				ADD(a, t-1, p);
			}
		}
		//cout<<"  "<<i<<"  "; DUMP_ALL(a);
	}

	return 1;
}