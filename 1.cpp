#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
using namespace std;

bool isPalindrom(string s){
	bool ans = true;
	for (int i = 0; i < s.length()/2; i++){
		if (ans)
			ans = ans && s[i] == s[s.length()-i-1];
	}
	return ans;
}
vector<string> PalindromFilter(vector<string> words, int minLength) {
	vector<string> res;
	for (string s: words){
		if (s.length() >= minLength && isPalindrom(s))
			res.push_back(s);
	}
	return res;
}



int main(){

	vector<string> words;
	words.push_back("aa");
	words.push_back("adada");
	words.push_back("aaaaa");
	words.push_back("abcd");
	vector<string> res = PalindromFilter(words, 1);
	for (string s: res)
		cout<<s<<endl;

	return 1;
}