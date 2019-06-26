#include <bits/stdc++.h>
using namespace std;
set<string> word_base_10000;
struct Node {
	char c;
	Node* chd[26];
	bool finish;
	Node() {
		c = '~';
		memset(chd, NULL, sizeof(chd));
		finish = 0;
	}
};
struct Trie {
	Node *_root;
	Trie() {
		_root = new Node;
	}
	void Insert(Node *&p, string s, int pos) {
		if (p == NULL) {
			p = new Node;
			p->c = s[pos];
		}
		if (pos != s.length() - 1) {
			Insert(p->chd[s[pos + 1] - 'a'], s, pos + 1);
		} else {
			p->finish = 1;
		}
	}
	bool Query(Node *&p, string s, int pos) {
		if (p == NULL) {
			return 0;
		}
		if (pos != s.length() - 1) {
			return Query(p->chd[s[pos + 1] - 'a'], s, pos + 1);
		} else if (p->finish) {
			return 1;
		} else {
			return 0;
		}
	}
};
Trie tr;
string s;
void input() {
	ifstream fin("[dictionary].txt");
	string s;
	while(fin >> s) {
		tr.Insert(tr._root, s, -1);
		// printf("Reading word\n");
	}
}
int main() {
	input();
	ifstream fin("[generate].txt");
	int x = 0;
	while(1) {
		cin >> s;
		if(tr.Query(tr._root, s, -1)) {
			x++;
		}
	}
	printf("%d", x);
	return 0;
} 
