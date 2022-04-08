#include<iostream>
#include<set>
#include <algorithm> 
#include<string>
#include<vector>
#include<map>


using namespace std;  //class

/*Реализуйте класс для человека, поддерживающий историю изменений человеком своих фамилии и имени.
Считайте, что в каждый год может произойти не более одного изменения фамилии и не более одного изменения имени. При этом с течением времени могут открываться всё новые факты из прошлого человека, поэтому года? в последовательных вызовах методов ChangeLastName и ChangeFirstName не обязаны возрастать.

Гарантируется, что все имена и фамилии непусты.

Строка, возвращаемая методом GetFullName, должна содержать разделённые одним пробелом имя и фамилию человека по состоянию на конец данного года.

Если к данному году не случилось ни одного изменения фамилии и имени, верните строку "Incognito".

Если к данному году случилось изменение фамилии, но не было ни одного изменения имени, верните "last_name with unknown first name".

Если к данному году случилось изменение имени, но не было ни одного изменения фамилии, верните "first_name with unknown last name".

+ метод GetFullNameWithHistory должен вернуть не только последние имя и фамилию к концу данного года, но ещё и все предыдущие имена и фамилии в обратном хронологическом порядке. Если текущие факты говорят о том, что человек два раза подряд изменил фамилию или имя на одно и то же, второе изменение при формировании истории нужно игнорировать.

Пример
int main() {
  Person person;
  
  person.ChangeFirstName(1965, "Polina");
  person.ChangeLastName(1967, "Sergeeva");
  for (int year : {1900, 1965, 1990}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1970, "Appolinaria");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1968, "Volkova");
  for (int year : {1969, 1970}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
  for (int year : {1960, 1967}) {
    cout << person.GetFullNameWithHistory(year) << endl;
  }
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;
  
  return 0;
}

output:
Incognito
Polina with unknown last name
Polina Sergeeva
Polina Sergeeva
Appolinaria (Polina) Sergeeva
Polina Volkova (Sergeeva)
Appolinaria (Polina) Volkova (Sergeeva)
Polina (Appolinaria, Polina) Volkova-Sergeeva (Volkova, Sergeeva)
Pauline (Polina) with unknown last name
Sergeeva with unknown first name
Pauline (Polina) Sergeeva
Pauline (Polina) Sergeeva (Ivanova, Sergeeva)
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

   string GetFullNameWithHistory(int year) {   // получить все имена и фамилии по состоянию на конец года year
	   pair <pair<string, vector <string>>, pair<string, vector <string>>> s = getFullInfo(year);
	   string fname = s.first.first;
	   string lname = s.second.first;
	   vector <string> hFname = s.first.second;
	   vector <string> hLname = s.second.second;
	   
	   string hf = "";
	   if  (!hFname.empty()){
		   hf = "(";
		   for (string i: hFname)
			   hf = hf + i + ", ";
		   hf.pop_back(); hf.pop_back(); 
		   hf = hf + ")";
	   }
	   
	   string hl;
	   if (!hLname.empty()){
		   hl = " (";
		   for (string i: hLname)
			   hl = hl + i + ", ";
		   hl.pop_back(); hl.pop_back(); 
		   hl = hl + ")";
	   }
		
	   if (fname != "0" && lname != "0"){
		   if (hf != "")
			   return fname + ' ' + hf + " " + lname + hl;
		   else
			   return fname + " " + lname + hl;
	   }
	   if (fname == "0" && lname == "0")
		   return "Incognito";
	   if (fname != "0"){
		   if (hf != "")
			   return fname + ' ' + hf + " with unknown last name";
		   else
			   return fname + " with unknown last name";
	   }
	   if (hl != "")
		   return lname + ' ' + hl + " with unknown first name";
	   else
		   return lname + " with unknown first name";

   
   }


private:
  map <int, string> hist_fname;
  map <int, string> hist_lname;

  pair <pair<string, vector <string>>, pair<string, vector <string>>> getFullInfo(int year){
	  pair <pair<string, vector <string>>, pair<string, vector <string>>> res;
	  res.first.first = "0";
	  res.second.first = "0";

	  vector<string> name;
	  for(pair<int, string>p: hist_fname)
		  if (p.first <= year){
			  if (name.empty() || p.second != *name.begin())
				  name.insert(name.begin(), p.second);
	 		  res.first.first = p.second;
		  }
	  if (!name.empty()){
		 name.erase(name.begin());
		 res.first.second = name;
	  }

	  name.clear();
	  for(pair<int, string>p: hist_lname)
		  if (p.first <= year){
			  if (name.empty() || p.second != *name.begin())
				  name.insert(name.begin(), p.second);
	 		  res.second.first = p.second;
		  }
	if (!name.empty()){
		 name.erase(name.begin());
		 res.second.second = name;
	  }

	  return res;
  }

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

  cout << person.GetFullNameWithHistory(1900) << endl;
  cout << person.GetFullNameWithHistory(1965) << endl;
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1970, "Appolinaria");

  cout << person.GetFullNameWithHistory(1969) << endl;
  cout << person.GetFullNameWithHistory(1970) << endl;
  
  person.ChangeLastName(1968, "Volkova");
    cout << person.GetFullNameWithHistory(1969) << endl;
	cout << person.GetFullNameWithHistory(1970) << endl;
  
  person.ChangeFirstName(1990, "Polina");
  person.ChangeLastName(1990, "Volkova-Sergeeva");
  cout << person.GetFullNameWithHistory(1990) << endl;
  
  person.ChangeFirstName(1966, "Pauline");
  cout << person.GetFullNameWithHistory(1966) << endl;
  
  person.ChangeLastName(1960, "Sergeeva");
    cout << person.GetFullNameWithHistory(1960) << endl;
	cout << person.GetFullNameWithHistory(1967) << endl;
  
  person.ChangeLastName(1961, "Ivanova");
  cout << person.GetFullNameWithHistory(1967) << endl;

  person.ChangeFirstName(1900, "Eugene");
  person.ChangeLastName(1900, "Sokolov");
  person.ChangeLastName(1910, "Sokolov");
  person.ChangeFirstName(1920, "Evgeny");
  person.ChangeLastName(1930, "Sokolov");
  cout << person.GetFullNameWithHistory(1940) << endl;
  
  return 0;
}
