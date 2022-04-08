#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
using namespace std;

/* WORRY i: �������� i-�� �������� � ������ ������� ��� ��������������;
QUIET i: �������� i-�� �������� ��� ��������������;
COME k: �������� k ��������� ������� � ����� �������;
COME -k: ������ k ������� �� ����� �������;
WORRY_COUNT: ������ ���������� ������������� ����� � �������.
8
COME 5
WORRY 1
WORRY 4
COME -2
WORRY_COUNT
COME 3
WORRY 3
WORRY_COUNT

output:
1
2
*/

void WORRY(vector<bool>& a,int i){
	a[i] = false;
}

void QUIET(vector<bool>& a,int i){
	a[i] = true;
}

void COME(vector<bool>& a, int k){
	if (k>0)
		for (int i = 0; i < k; i++)
			a.push_back(true);
	else
		for (int i = 0; i < -k; i++)
			a.pop_back();
}

int WORRY_COUNT(vector<bool>& a){
	int c = 0;
	for( bool b: a)
		if (!b) c++;
	return c;
}


int main(){
	ifstream f("com_3.txt");
	vector<bool> a;
	int n; f >> n;
	for (int i = 0; i < n; i++){
		string s;
		f >> s;
		if (s == "WORRY_COUNT") 
			cout << WORRY_COUNT(a)<<endl;
		else{
			int t; f >> t;
			if (s=="COME") COME(a, t);
			else if (s=="WORRY") WORRY(a, t);
			else if (s=="QUIET") QUIET(a, t);
			else if (s=="WORRY") WORRY(a, t);
		}
	}

	return 1;
}