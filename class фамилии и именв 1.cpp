#include<iostream>
#include<set>
#include <algorithm> 
#include<string>
#include<vector>
#include<map>


using namespace std;  //class  ������� � �����

/*���������� ����� ��� ��������, �������������� ������� ��������� ��������� ����� ������� � �����.
��������, ��� � ������ ��� ����� ��������� �� ����� ������ ��������� ������� � �� ����� ������ ��������� �����. ��� ���� � �������� ������� ����� ����������� �� ����� ����� �� �������� ��������, ������� ����? � ���������������� ������� ������� ChangeLastName � ChangeFirstName �� ������� ����������.

�������������, ��� ��� ����� � ������� �������.

������, ������������ ������� GetFullName, ������ ��������� ���������� ����� �������� ��� � ������� �������� �� ��������� �� ����� ������� ����.

���� � ������� ���� �� ��������� �� ������ ��������� ������� � �����, ������� ������ "Incognito".

���� � ������� ���� ��������� ��������� �������, �� �� ���� �� ������ ��������� �����, ������� "last_name with unknown first name".

���� � ������� ���� ��������� ��������� �����, �� �� ���� �� ������ ��������� �������, ������� "first_name with unknown last name".

������
int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}

output:
Incognito
Polina with unknown last name
Polina Sergeeva
Polina Sergeeva
Appolinaria Sergeeva
Polina Volkova
Appolinaria Volkova


*/

class Person {
public:
  void ChangeFirstName(int year, const string& first_name) {
	  hist_fname[year] = first_name;
  }

  void ChangeLastName(int year, const string& last_name) {
       hist_lname[year] = last_name;
  }

  string GetFullName(int year) {
	 pair<string, string> s = getInfo(year);
	 string fname = s.first;
	 string lname = s.second;
	 
	 if (fname != "0" && lname != "0")
		 return fname + ' ' + lname;
	  if (fname == "0" && lname == "0")
		 return "Incognito";
	 if (fname != "0")
		 return fname + " with unknown last name";
	 return lname + " with unknown first name";
  }

private:
  map <int, string> hist_fname;
  map <int, string> hist_lname;

  pair<string, string>  getInfo(int year){
	  pair<string, string> res; 
	  res = make_pair("0", "0");

	  for(pair<int, string>p: hist_fname)
		  if (p.first <= year)
			  res.first = p.second;

	  for(pair<int, string>p: hist_lname)
		  if (p.first <= year)
			  res.second = p.second;
	  
	  return res;
  }
};


int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");

  int a[3] = {1900, 1965, 1990};
  set<int> s(a, a+3);

  for (int year : s) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  
  int a2[2] = {1969, 1970};
  set<int> s2(a2, a2+2); 
  
  for (int year : s2) {
    cout << person.GetFullName(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
   
  int a3[2] = {1969, 1970};
  set<int> s3(a3, a3+2); 

  for (int year : s3) {
    cout << person.GetFullName(year) << endl;
  }
  
  return 0;
}
