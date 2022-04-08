#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<fstream>
#include <algorithm> 
#include <functional>
#include<string>
#include<vector>
#include<map>
#include<locale>

using namespace std;  //сортировка строк без учета регистра

bool f_(string l, string r){
		 transform(l.begin(), l.end(),l.begin(), ::toupper);
		 transform(r.begin(), r.end(),r.begin(), ::toupper);
		 return l < r ;
}

int main(){
	ifstream f("com_3.txt", ios::in);

	int n;
	cin >> n;
	vector <string> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];
	
	std::sort (a.begin(), a.end(), f_);

	for (string v:a)
		cout<< v << " ";

	

	return 1;
}