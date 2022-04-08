#include<iostream>
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
}