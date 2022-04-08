#include<iostream>
#include<fstream>
#include <algorithm>  
#include<string>
#include<vector>
#include<set>
#include<map>

using namespace std;  

//set

/*��� ����� ���������� ���������� ���� �����, ���� ��� ����� ������� ��������. ���������� ��������� �������� ��� ������� ���������:

ADD word1 word2 � �������� � ������� ���� ��������� (word1, word2).

COUNT word � ������ ���������� ��������� ����� word.

CHECK word1 word2 � ���������, �������� �� ����� word1 � word2 ����������. ����� word1 � word2 ��������� ����������, ���� ����� �������� ADD ��� ���� �� ���� ������ ADD word1 word2 ��� ADD word2 word1.

���������
��� ���������, ����� �������, ��� �������� �� �������� ���������������, �� ����, ���� A - ������� B, � B - ������� C, �� �� ����� �� �������, ��� A - ������� C.

������ �����
������� �������� ���������� �������� Q, ����� Q ����� � ���������� ��������. �������������, ��� � ������ ������� CHECK � ADD ����� word1 � word2 ��������. ��� ����� ������� ���� �� ��������� ����, ���� � �������� �������������.

������ ������
��� ������� ������� � ��������������� ������ �������� ����� �� ����:

� ����� �� ������ COUNT word �������� ������������ ����� ����� � ���������� ��������� ����� word.

� ����� �� ������ CHECK word1 word2 �������� ������ YES, ���� word1 � word2 �������� ����������, � NO � ��������� ������.

������
����
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

void ADD(map <string, set <string>> & dict, string word1, string word2){ // �������� � ������� ���� ��������� (word1, word2).
	dict[word1].insert(word2);
	dict[word2].insert(word1);
}

int COUNT(const map <string, set <string>> & dict, string word){// ������ ���������� ��������� ����� word.
	if(dict.count(word))
		return dict.at(word).size();
	else return 0;
}

string CHECK(const map <string, set <string>> & dict, string word1, string word2){// ���������, �������� �� ����� word1 � word2 ����������. ����� word1 � word2 ��������� ����������, ���� ����� �������� ADD ��� ���� �� ���� ������ ADD word1 word2 ��� ADD word2 word1.
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