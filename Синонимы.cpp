#include<iostream>
#include<fstream>
#include <algorithm>  
#include<string>
#include<vector>
#include<set>
#include<map>

using namespace std;  

//set

/*Два слова называются синонимами друг друга, если они имеют похожие значения. Реализуйте следующие операции над словарём синонимов:

ADD word1 word2 — добавить в словарь пару синонимов (word1, word2).

COUNT word — узнать количество синонимов слова word.

CHECK word1 word2 — проверить, являются ли слова word1 и word2 синонимами. Слова word1 и word2 считаются синонимами, если среди запросов ADD был хотя бы один запрос ADD word1 word2 или ADD word2 word1.

Замечание
Для упрощения, будем считать, что синонимы не обладают транзитивностью, то есть, если A - синоним B, а B - синоним C, то из этого НЕ следует, что A - синоним C.

Формат ввода
Сначала вводится количество запросов Q, затем Q строк с описаниями запросов. Гарантируется, что в каждом запросе CHECK и ADD слова word1 и word2 различны. Все слова состоят лишь из латинских букв, цифр и символов подчёркивания.

Формат вывода
Для каждого запроса в соответствующей строке выведите ответ на него:

В ответ на запрос COUNT word выведите единственное целое число — количество синонимов слова word.

В ответ на запрос CHECK word1 word2 выведите строку YES, если word1 и word2 являются синонимами, и NO в противном случае.

Пример
Ввод
8
ADD program code
COUNT cipher
ADD code cipher
COUNT code
COUNT program
CHECK code program
CHECK program cipher
CHECK cpp java

output:
0
2
1
YES
NO
NO

*/

void ADD(map <string, set <string>> & dict, string word1, string word2){ // добавить в словарь пару синонимов (word1, word2).
	dict[word1].insert(word2);
	dict[word2].insert(word1);
}

int COUNT(const map <string, set <string>> & dict, string word){// узнать количество синонимов слова word.
	if(dict.count(word))
		return dict.at(word).size();
	else return 0;
}

string CHECK(const map <string, set <string>> & dict, string word1, string word2){// проверить, являются ли слова word1 и word2 синонимами. Слова word1 и word2 считаются синонимами, если среди запросов ADD был хотя бы один запрос ADD word1 word2 или ADD word2 word1.
	if (dict.count(word1) && dict.at(word1).count(word2) > 0)
		return "YES";
	else 
		return "NO";
}

int main(){
	ifstream f("com_3.txt", ios::in);
	map <string, set <string>>  dict;
	 
	int n; cin >> n;
	//f >> n;

	while(n--){
		string cmd; cin >> cmd;
		//f >> cmd;
		if (cmd == "ADD"){
			string s1,s2;  cin>>s1>>s2;
			//f >>s1>>s2; 
			ADD(dict, s1, s2);
		}
		else if (cmd == "COUNT"){
			string s1;  cin>>s1;
			//f >> s1; 
			cout << COUNT(dict, s1)<<endl;
		}
		if (cmd == "CHECK"){
			string s1, s2;  cin>>s1>>s2;
			//f >> s1 >> s2; 
			cout << CHECK(dict, s1, s2)<<endl;
		}
	}


	return 1;
}