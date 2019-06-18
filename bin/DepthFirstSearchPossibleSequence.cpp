#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e4;
const int MAXM = 1e4;
int M, N, D; // M个父节点 N个子节点 
int u, v; // 输边用变量  
int adj_list[MAXN][MAXM]; // 邻接表 
int adj_leng[MAXN] = {0}; // 邻接表长度
int tmp_seq[MAXM] = {0};
void dfs(int depth, int tmp_num) {
	if(depth == D) {
		for(int i = 1 ; i <= D ; i ++) {
			cout << tmp_seq[i] << " ";
		}
		cout << endl;
		return;
	}
	tmp_seq[depth + 1] = tmp_num;
	for(int i = 1 ; i <= adj_leng[tmp_num] ; i ++) {
		dfs(depth + 1, adj_list[tmp_num][i]);
	}
	tmp_seq[depth + 1] = 0;
	return;
}
int main() {
	cin >> D >> M;
	for(int i = 1 ; i <= M ; i ++) {
		cin >> u >> N;
		for(int j = 1 ; j <= N ; j ++) {
			cin >> v;
			adj_list[u][++ adj_leng[u]] = v;
		}
	}
	dfs(0, 0);
	return 0;
}
//GYH JZH GAY
