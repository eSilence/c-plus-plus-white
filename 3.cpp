#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(){
	string s = "fasdfasdfadasdf";
	//cin>>s;
	int k = s.find('f');
	if (k >= 0){
		k = s.find('f', k+1);
		if (k > 0)
			cout<<k;
		else
			cout<<-1;
	}
	else
		cout << -2;

return 1;
}