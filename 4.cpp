#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(){
	unsigned int a;
	cin>>a;
	char c[15];
	string s = string(_itoa(a, c, 2));
	
	cout<<s;


return 1;
}