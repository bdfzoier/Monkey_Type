//用new定义数组
//能更大
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int NR=1000;
const int SON=100;
struct word_chain{
	map<string,int> indexof;
	string stringof[NR];
	int last_part_index/*最后一个组的编号*/;
	int** son;
	int *son_t;
	//int not_son[NR][NR],not_son_t[NR];
	//记录该声韵母组后面可以或者不可以接什么
	word_chain(){
		son=new int*[NR];
		for(int i=0;i<NR;i++)
			son[i]=new int[SON];
		son_t=new int[NR];
		last_part_index=0;
		for(int i=0;i<NR;i++)
			memset(son[i],-1,SON*sizeof(int));
		memset(son_t,0,NR*sizeof(int));
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
		int hasid=indexof[str];
		if(hasid)return hasid;
		indexof[str]=++last_part_index;
		stringof[last_part_index]=str;
		return last_part_index; 
	}
	inline void push_next(string cur,string next){
		int id_cur=newstr(cur);
		int id_next=newstr(next);
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
	//第一个参数:统计并清楚编号为strnum的节点的子节点
	//第二个参数:清除出现次数少于k的
	void clean(int strnum,int k){
		sort(son[strnum]+1,son[strnum]+son_t[strnum]+1);
		int cnt=0;
		for(int i=son_t[strnum];i>=1;i--){
			if(son[strnum][i]==son[strnum][i-1] && (i>=1)){
				cnt++;
				son[strnum][i]=-1;
			}
			else {
				if(cnt<(k-1))
					son[strnum][i]=-1;
				cnt=0;
			}
		}
		int index_of_done=1;
		for(int i=1;i<=son_t[strnum];i++){
			if(son[strnum][i]==-1)continue;
			son[strnum][index_of_done]=son[strnum][i];
			if(i!=index_of_done)son[strnum][i]=-1;
			index_of_done++;
		}
		son_t[strnum]=index_of_done-1;
	}
};
