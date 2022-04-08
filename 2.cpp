#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;

void MoveStrings(vector<string> &source, vector<string> &destination) {
	vector<string> res;
	for (string s: source)
		destination.push_back(s);

	source.clear();
}



int main(){

	vector<string> words;
	words.push_back("aa");
	words.push_back("adada");
	words.push_back("aaaaa");
	words.push_back("abcd");
	vector<string> words2;
	words.push_back("1");
	words.push_back("2");
	words.push_back("3");
	words.push_back("4");
	MoveStrings(words, words2);
	cout<<"-- 1 --\n";
	for (string s: words)
		cout<<s<<endl;
	cout<<"-- 2 --\n";
	for (string s: words2)
		cout<<s<<endl;

	return 1;
}