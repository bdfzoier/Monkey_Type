// <README>
// 此判断程序必须有10000单词的词库和此程序在同一目录下才可以正常运作
// 且10000单词的词库必须被命名为1000-wbase.txt
// <\README>

#include <bits/stdc++.h>
using namespace std;
set<string> word_base_10000;
string s;
void input() {
	ifstream fin("1000-wbase.txt");
	string s;
	while(fin >> s) {
		word_base_10000.insert(s);
		// printf("Reading word\n");
	}
}
int main() {
	input();
	while(1) {
		cout << "Enter the word that you want to check." << endl;
		cout << "Console >> ";
		cin >> s;
		if(word_base_10000.find(s) != word_base_10000.end()) {
			cout << "The word you entered is valid." << endl;
		}
		else {
			cout << "The word you entered is invalid. Please try again." << endl;
		}
	}
	return 0;
} 
