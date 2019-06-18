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
		memset(next_can,0,sizeof(next_can));
		//memset(next_cant,-1,sizeof(next_cant));
		memset(next_can_t,0,sizeof(next_can_t));
		//memset(next_cant_t,0,sizeof(next_cant_t));
	}
	//清除出现次数少于k的
	void print(){
		for(int i=1;i<=last_part_index;i++){
			printf("i=%d,string=",i);
			cout<<stringof[i];
			for(int j=1;j<=next_can_t[i];j++){
				printf(" %d",next_can[i][j]);
				cout<<stringof[next_can[i][j]]<<", ";
			}
			printf("\n");
		}
	}
	void clean(int strnum,int k){//hasbug
		sort(next_can[strnum]+1,next_can[strnum]+next_can_t[strnum]+1);
		//print();
		int cnt=0;
		for(int i=next_can_t[strnum];i>=1;i--){
			if(next_can[i]==next_can[i-1]&& (i!=1)){
				cnt++;
				next_can[strnum][i]=-1;
			}
			else {
				if(cnt<(k-1))
					next_can[strnum][i]=-1;
				cnt=0;
			}
		}
		//cout<<next_can_t[strnum];
		//print();
			for(int j=1;j<=next_can_t[strnum];j++){
				//cout<<j;
				printf(" %d",next_can[strnum][j]);
				//cout<<stringof[next_can[strnum][j]]<<", ";
			}
		int index_of_done=1;
		for(int i=1;i<=next_can_t[strnum];i++){
			if(next_can[strnum][i]==-1)continue;
			next_can[strnum][index_of_done]=next_can[strnum][i];
			if(next_can[strnum][i]!=index_of_done)next_can[strnum][i]=0;
			index_of_done++;
		}
		next_can_t[strnum]=index_of_done-1;
		//cout<<next_can[strnum][index_of_done]<<"adpapd";
	}
	void newstr(string str){
		if(indexof[str])return;
		indexof[str]=++last_part_index;
		stringof[last_part_index]=str;
	}
	void push_next_can(int cur,int next){
		next_can[cur][++next_can_t[cur]]=next;
	}
};
//arr[s] to arr[t],including start&end
//arr[i]>0,return the end index-after-del;
int remove_extra(int *arr,int s,int t,int k){
	sort(arr+s,arr+t+1);
	int cnt=0;
	for(int i=t;i>=s;i--)
		if(arr[i]==arr[i-1]){
			cnt++;
			arr[i]=-1;
		}
		else {
			if(cnt<(k-1))
				arr[i]=-1;
			cnt=0;
		}
	int index_of_done=s;
	for(int i=s;i<=t;i++){
		if(arr[i]==-1)continue;
		arr[index_of_done]=arr[i];
		if(arr[i]!=index_of_done)arr[i]=0;
		index_of_done++;
	}
	return index_of_done-1;
}
int main(){
	//freopen("test.in","r",stdin);
	//word_chain fk;
	//string s="haha";
	//string s2="fuck";
	//string s3="kiafuha";
	//fk.newstr(s);
	//fk.newstr(s2);
	//fk.newstr(s3);
	//fk.push_next_can(1,2);
	//fk.push_next_can(1,2);
	//fk.push_next_can(1,3);
	//fk.print();
	//puts("-----------------------------------------------------");
	//fk.clean(1,2);
	//fk.print();
	int l[4]={0,2,2,3};
	remove_extra(l,1,3,2);
	for(int i=1;i<=3;i++)
		cout<<l[i];
	return 0;
}
