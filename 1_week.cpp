#include<iostream>
using namespace std;
int main(){
	int a, b;
	cin>>a>>b;
	int c = a+b;
	cout<<c;

return 1;
}#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main(){
	double a,b,c;
	cin>>a>>b>>c;
	if (a != 0){
		double d = b*b-4*a*c;
		if (d > 0){
			double x1 = (-b + sqrt(d))/(2*a);
			double x2 = (-b - sqrt(d))/(2*a);
			cout<<x1<<' '<<x2;
		}
		else if (d==0){
			double x = -b /(2*a);
			cout<<x;
		}
	}
	else if (b!=0){ //bx+c = 0
		double x = -c/b;
		cout<<x;
	}
	


return 1;
}#include<iostream>
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
}#define _CRT_SECURE_NO_WARNINGS
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
}