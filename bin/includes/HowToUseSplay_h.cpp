#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdio>
#include "splay.h"
using namespace std;
Splay spy;
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1;i <= n;i++) {
		int opt;
		string s;
		cin >> opt >> s;
		if (opt == 1) {
			int k;
			cin >> k;
			spy.Update(s, k);
		} else {
			printf("%d\n", spy.Query(s));
		}
	}
	return 0;
}
