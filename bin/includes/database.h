//用new定义数组
//能更大
#ifndef DATABASE_H
#define DATABASE_H 1

#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>

#define NR 100000
#define SON 5000
#define MXN 10000

using namespace std;
struct Node {
	int siz, k;
	std::string val;
	Node *l, *r;
	Node() {
		k = siz = 0;
		val = "";
		l = r = NULL;
	}
	void Update() {
		siz = (l == NULL ? 0 : l->siz) + (r == NULL ? 0 : r->siz) + 1;
	}
};
struct Splay {
	private:
	Node *_root;
	void New(Node *&p, std::string val) {
		p = new Node;
		p->val = val;
		p->siz = 1;
	}
	void RotateL(Node *&p) {
		Node *q = p->r;
		p->r = q->l;
		q->l = p;
		p->Update();
		p = q;
		p->Update();
	}
	void RotateR(Node *&p) {
		Node *q = p->l;
		p->l = q->r;
		q->r = p;
		p->Update();
		p = q;
		p->Update();
	}
	void Splay_(Node *&p, std::string val) {
		if (p->val == val) {
			return;
		}
		if (p->val > val) {
			if (p->l->val == val) {
				RotateR(p);
			} else if (p->l->val > val) {
				Splay_(p->l->l, val);
				RotateR(p);
				RotateR(p);
			} else {
				Splay_(p->l->r, val);
				RotateL(p->l);
				RotateR(p);
			}
		} else {
			if (p->r->val == val) {
				RotateL(p);
			} else if (p->r->val < val) {
				Splay_(p->r->r, val);
				RotateL(p);
				RotateL(p);
			} else {
				Splay_(p->r->l, val);
				RotateR(p->r);
				RotateL(p);
			}
		}
	}
	void Update_(Node *&p, std::string s, int k) {
		if (p == NULL) {
			New(p, s);
			p->k = k;
			return;
		}
		if (p->val == s) {
			p->k = k;
		} else if (p->val > s) {
			Update_(p->l, s, k);
		} else {
			Update_(p->r, s, k);
		}
		p->Update();
	}
	int Query_(Node *p, std::string s) {
		if (p == NULL) {
			return 0;
		}
		if (p->val == s) {
			return p->k;
		} else if (p->val > s) {
			return Query_(p->l, s);
		} else {
			return Query_(p->r, s);
		}
	}
	void Destruct(Node *&p) {
		if (p == NULL) {
			return;
		}
		Destruct(p->l);
		Destruct(p->r);
		delete p;
	}
	public:
	Splay() {
		New(_root, "!");
		New(_root->r, "~");
	}
	void Update(std::string s, int k) {
		Update_(_root, s, k);
		Splay_(_root, s);
	}
	int Query(std::string s) {
		return Query_(_root, s);
	}
	~Splay() {
		Destruct(_root);
	}
};
inline bool is_vowel(char x){
	return (x=='a')||(x=='e')||(x=='i')||(x=='o')||(x=='u');
}
struct word_chain{
	Splay indexof;
	string stringof[NR],cur,last,read;
	int last_part_index/*最后一个组的编号*/,endindex;
	int save[MXN];
	bool vis[NR];
	int** son;
	int *son_t;
	//int not_son[NR][NR],not_son_t[NR];
	//记录该声韵母组后面可以或者不可以接什么
	word_chain(){
		son=new int*[NR];
		for(int i=0;i<NR;i++)
			son[i]=new int[SON];
		son_t=new int[NR];
		for(int i=0;i<NR;i++)
			memset(son[i],-1,SON*sizeof(int));
		memset(son_t,0,NR*sizeof(int));
		memset(vis,0,sizeof(vis));
		last_part_index=0;
		newstr("start");
		newstr("end");
		endindex=2;
		printf("Variable initialization completed.\n");
		//memset(not_son,-1,sizeof(not_son));
		//memset(not_son_t,0,sizeof(not_son_t));
	}
	void freespace(){
		for(int i=0;i<NR;i++)
			delete[] son[i];
		delete[] son;
		delete[] son_t;
	}
	//-----------------------------function using map start--------------------------------------
	inline int newstr(string str){
		int hasid=indexof.Query(str);
		if(hasid)return hasid;
		if(last_part_index==NR-1){
			printf("arr exceeded(NR needs to be bigger)\n");
			return 0;
		}
		indexof.Update(str, ++last_part_index);
		stringof[last_part_index]=str;
		return last_part_index; 
	}
	inline void push_next(string cur,string next){
		int id_cur=newstr(cur);
		int id_next=newstr(next);
		if(son_t[id_cur]==SON-1){
			printf("arr exceeded(SON needs to be bigger)\n");
			return;
		}
		son[id_cur][++son_t[id_cur]]=id_next;
	}
	inline void print(){
		for(int i=1;i<=last_part_index;i++){
			printf("num:%d\tstring:",i);
			cout<<stringof[i]<<"\tsons:[";
			for(int j=1;j<=son_t[i];j++){
				printf(" %d",son[i][j]);
				if(son[i][j]>0)
					cout<<stringof[son[i][j]];
				else printf("**<0**");
			}
			printf(" ]\n");
		}
	}
	//-----------------------------function using map end--------------------------------------
	//第一个参数:统计并清除法编号为strnum的节点的子节点
	//第二个参数:清除出现次数少于k的
	void startdfs(int mxd,int start_node){
		memset(vis,0,sizeof(vis));
		vis[start_node]=1;
		dfs(mxd,0,start_node);
	}
	void dfs(int D,int curd,int cur){
		if(cur==endindex){
			for(int i=1;i<curd;i++)
				cout<<stringof[save[i]];
			printf("\n");
			return;
		}
		if(curd==D)return;
		save[curd]=cur;
		for(int i=1;i<=son_t[cur];i++){
			if(!vis[son[cur][i]]){
				vis[son[cur][i]]=1;
				dfs(D,curd+1,son[cur][i]);
				vis[son[cur][i]]=0;
			}
		}
	}
	void input(){
		last="start";
		cin>>read;
		int t=0;
		//每一部分循环一次
		int len=(int)read.length();
		while(t<len){
			//分离元音组和辅音组
			if(is_vowel(read[t])){
				//记录该部分的开始下标
				int savet=t;
				while(is_vowel(read[t])&&t<len)t++;
				cur.assign(read,savet,t-savet);
			}
			else{
				//记录该部分的开始下标
				int savet=t;
				while(!is_vowel(read[t])&&t<len)t++;
				cur.assign(read,savet,t-savet);
			}
			push_next(last,cur);
			last=cur;
		}
		push_next(last,"end");
	}
	void clean(int strnum,int k){
		sort(son[strnum]+1,son[strnum]+son_t[strnum]+1);
		int cnt=0;
		for(int i=son_t[strnum];i>=1;i--){
			if(son[strnum][i]==son[strnum][i-1] && (i>=1)){
				cnt++;
				son[strnum][i]=-1;
			}
			else {
				if(cnt<(k-1) && stringof[son[strnum][i]]!="end")
					son[strnum][i]=-1;
				cnt=0;
			}
		}
		int index_of_done=1;
		for(int i=1;i<=son_t[strnum];i++){
			if(son[strnum][i]==-1)continue;
			if(i!=index_of_done){
				son[strnum][index_of_done]=son[strnum][i];
				son[strnum][i]=-1;
			}
			index_of_done++;
		}
		son_t[strnum]=index_of_done-1;
	}
};
#undef NR
#undef SON
#undef MXN

#endif
