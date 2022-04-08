#include<iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>

using namespace std;  // c��������� �� ���� ��������. �� ������ ��� � ������� �� ���� ��������

vector<string> FindNamesHistory(const map<int, string>& names_by_year, const int year) {
  vector<string> names;
  // ���������� ��� ������� � ��������������� �������
  for (const auto& item : names_by_year) {
    // ���� ��������� ��� �� ��������� � �������� � ���������� �� �����������,
    if (item.first <= year && (names.empty() || names.back() != item.second)) {
      // ��������� ��� � �������
      names.push_back(item.second);
    }
  }
  return names;
}

string BuildJoinedName(vector<string> names) {
  // ��� ������� � ��� ����������
  if (names.empty()) {
    return "";
  }
  // ������ ������ ��������������� ������� �� ��������
  reverse(begin(names), end(names));
  
  // �������� ������� ������ ��� � ������ ����������
  string joined_name = names[0];
  
  // ���������� ��� ����������� �����
  for (size_t i = 1; i < names.size(); ++i) {
    if (i == 1) {
      // ���� ��� ������ ������������� ���, �������� ��� �� ���������� �������
      joined_name += " (";
    } else {
      // ���� ��� �� ������ ���, �������� �� ����������� �������
      joined_name += ", ";
    }
    // � ��������� ��������� ���
    joined_name += names[i];
  }
  
  // ���� � ������� ���� ������ ������ �����, �� ��������� ������ � ������� �
  if (names.size() > 1) {
    joined_name += ")";
  }
  // ��� �� ���� �������� ������
  return joined_name;
}

// ��. ������� ���������� ������
string BuildFullName(const string& first_name, const string& last_name) {
  if (first_name.empty() && last_name.empty()) {
    return "No person";
  } else if (first_name.empty()) {
    return last_name + " with unknown first name";
  } else if (last_name.empty()) {
    return first_name + " with unknown last name";
  } else {
    return first_name + " " + last_name;
  }
}

class Person {
public:
	Person(string fn, string ln, int year){
		first_names[year] = fn;
		last_names[year] = ln;

	}

  void ChangeFirstName(int year, const string& first_name) {
	  int year_ = first_names.begin()->first;
	  if (!first_names.empty() && year >= year_)
		  first_names[year] = first_name;
  }

  void ChangeLastName(int year, const string& last_name) {
	  int year_ = last_names.begin()->first;
	  if (!last_names.empty() && year >= year_)
		last_names[year] = last_name;
  }
  
  string GetFullName(int year) const {
    // ����� ������� ��������� ����� � �������
    // � ������ ������ ��� �������, ��� ��� ��� ���������� ������ ��������� ��� � �������, �� ������ �� �� ������������ ������� �������?
    const vector<string> first_names_history = FindFirstNamesHistory(year);
    const vector<string> last_names_history = FindLastNamesHistory(year);
    
    // ���������� ������ ��� ������� BuildFullName: ������ ��������� ��� � ������� ��� ������� �� �������, ���� ��� ����������
    string first_name;
    string last_name;
    if (!first_names_history.empty()) {
      first_name = first_names_history.back();
    }
    if (!last_names_history.empty()) {
      last_name = last_names_history.back();
    }
    return BuildFullName(first_name, last_name);
  }
  
  string GetFullNameWithHistory(int year) const {
    // ������� ������ ��� �� ���� ��������
    const string first_name = BuildJoinedName(FindFirstNamesHistory(year));
    // ������� ������ ������� �� ���� ��������
    const string last_name = BuildJoinedName(FindLastNamesHistory(year));
    // ��������� �� � ������� ������� �������
    return BuildFullName(first_name, last_name);
  }

private:
  vector<string> FindFirstNamesHistory(int year) const {
    return FindNamesHistory(first_names, year);
  }
  vector<string> FindLastNamesHistory(int year) const {
    return FindNamesHistory(last_names, year);
  }

  map<int, string> first_names;
  map<int, string> last_names;
};

int main() {
	{
		Person person("first", "last", 1);
		person.ChangeLastName(0, std::to_string(42) + "_Ilast");
		person.ChangeFirstName(0, std::to_string(1) + "1212");
		std::cout << person.GetFullNameWithHistory(2) << '\n';
		std::cout << person.GetFullName(2) << '\n';
	}
	
	{
		 Person person("Polina", "Sergeeva", 1960);
		 int a[] = {1959, 1960};
			vector <int> va(a, a+2);

		for (int year : a) {
			cout << person.GetFullNameWithHistory(year) << endl;
		}

		person.ChangeFirstName(1965, "Appolinaria");
		person.ChangeLastName(1961, "Ivanova");
		person.ChangeFirstName(1964, "Polina");
		person.ChangeLastName(1961, "Ivanova");
		int a2[] = {1965, 1967};
			vector <int> va2(a2, a2+2);
		for (int year : va2) {
			cout << person.GetFullNameWithHistory(year) << endl;
		}

	}
	//{

	//	//-----------------------  ����� �������� 3 ---------- 
	//	Person person("Polina", "Sergeeva", 1960);
	//	int a[] = {1959, 1960};
	//	vector <int> va(a, a+2);
	//		for (int year : va) {
	//		cout << person.GetFullNameWithHistory(year) << endl;
	//	}
 // 
	//	person.ChangeFirstName(1965, "Appolinaria");
	//	person.ChangeLastName(1967, "Ivanova");
	//
	//	int a2[] = {1965, 1967};
	//	vector <int> va2(a2, a2+2);
	//	for (int year : va2) {
	//		cout << person.GetFullNameWithHistory(year) << endl;
	//	}
	//}
  //-----------------------  ����� �������� 2 ---------- ���������� ������� -----------

 // Person person;
  
 // person.ChangeFirstName(1965, "Polina");
 // person.ChangeLastName(1967, "Sergeeva");

 // cout << person.GetFullNameWithHistory(1900) << endl;
 // cout << person.GetFullNameWithHistory(1965) << endl;
 // cout << person.GetFullNameWithHistory(1990) << endl;
 // 
 // person.ChangeFirstName(1970, "Appolinaria");

 // cout << person.GetFullNameWithHistory(1969) << endl;
 // cout << person.GetFullNameWithHistory(1970) << endl;
 // 
 // person.ChangeLastName(1968, "Volkova");
 //   cout << person.GetFullNameWithHistory(1969) << endl;
	//cout << person.GetFullNameWithHistory(1970) << endl;
 // 
 // person.ChangeFirstName(1990, "Polina");
 // person.ChangeLastName(1990, "Volkova-Sergeeva");
 // cout << person.GetFullNameWithHistory(1990) << endl;
 // 
 // person.ChangeFirstName(1966, "Pauline");
 // cout << person.GetFullNameWithHistory(1966) << endl;
 // 
 // person.ChangeLastName(1960, "Sergeeva");
 //   cout << person.GetFullNameWithHistory(1960) << endl;
	//cout << person.GetFullNameWithHistory(1967) << endl;
 // 
 // person.ChangeLastName(1961, "Ivanova");
 // cout << person.GetFullNameWithHistory(1967) << endl;

 // person.ChangeFirstName(1900, "Eugene");
 // person.ChangeLastName(1900, "Sokolov");
 // person.ChangeLastName(1910, "Sokolov");
 // person.ChangeFirstName(1920, "Evgeny");
 // person.ChangeLastName(1930, "Sokolov");
 // cout << person.GetFullNameWithHistory(1940) << endl;
  
  return 0;
}

