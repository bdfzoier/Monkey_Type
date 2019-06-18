#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int NR=1000;
const int MXN=100;
struct word_chain{
	map<string,int> indexof;
	string stringof[NR];
	int last_part_index/*最后一个组的编号*/;
	int next_can[NR][MXN],next_can_t[NR];
	//int next_cant[NR][NR],next_cant_t[NR];
	//记录该声韵母组后面可以或者不可以接什么
	word_chain(){
		last_part_index=0;
		memset(next_can,-1,sizeof(next_can));
		memset(next_can_t,0,sizeof(next_can_t));
		//memset(next_cant,-1,sizeof(next_cant));
		//memset(next_cant_t,0,sizeof(next_cant_t));
	}
	//-----------------------------function using map start--------------------------------------
	inline int newstr(string str){
		int hasid=indexof[str];
		if(hasid)return hasid;
		indexof[str]=++last_part_index;
		stringof[last_part_index]=str;
		return last_part_index; 
	}
	inline void push_next_can(string cur,string next){
		int id_cur=newstr(cur);
		int id_next=newstr(next);
		next_can[id_cur][++next_can_t[id_cur]]=id_next;
	}
	inline void print(){
		for(int i=1;i<=last_part_index;i++){
			printf("i=%d,string=",i);
			cout<<stringof[i];
			for(int j=1;j<=next_can_t[i];j++){
				printf(" %d",next_can[i][j]);
				if(next_can[i][j]>0)
					cout<<stringof[next_can[i][j]]<<", ";
				else cout<<"**below0**";
			}
			printf("\n");
		}
	}
	//-----------------------------function using map end--------------------------------------
	//第一个参数:统计并清楚编号为strnum的节点的子节点
	//第二个参数:清除出现次数少于k的
	void clean(int strnum,int k){
		sort(next_can[strnum]+1,next_can[strnum]+next_can_t[strnum]+1);
		int cnt=0;
		for(int i=next_can_t[strnum];i>=1;i--){
			if(next_can[strnum][i]==next_can[strnum][i-1] && (i>=1)){
				cnt++;
				next_can[strnum][i]=-1;
			}
			else {
				if(cnt<(k-1))
					next_can[strnum][i]=-1;
				cnt=0;
			}
		}
		int index_of_done=1;
		for(int i=1;i<=next_can_t[strnum];i++){
			if(next_can[strnum][i]==-1)continue;
			next_can[strnum][index_of_done]=next_can[strnum][i];
			if(i!=index_of_done)next_can[strnum][i]=-1;
			index_of_done++;
		}
		next_can_t[strnum]=index_of_done-1;
	}
};
int main(){
	word_chain fk;
	string s="haha";
	string s2="fuck";
	string s3="kiafuha";
	fk.push_next_can(s,s2);
	fk.push_next_can(s,s2);
	fk.push_next_can(s,s3);
	fk.print();
	puts("-----------------------------------------------------");
	fk.clean(1,2);
	fk.print();
	return 0;
}
