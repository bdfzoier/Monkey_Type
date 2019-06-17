#include<iostream>
#include<cstdio>
#include<algorithm>
#include<map>
using namespace std;
const int NR=1000;
struct word_chain{
	map<string,int> indexof;
	string stringof[NR];
	int last_part_index/*最后一个组的编号*/;
	int next_can[NR][NR],next_can_t[NR];
	int next_cant[NR][NR],next_cant_t[NR];
	//记录该声/韵母组后面可以/不可以接什么
	word_chain{
		last_part_index=0;
		memset(next_can,-1,sizeof(next_can));
		memset(next_cant,-1,sizeof(next_cant));
		memset(next_can_t,0,sizeof(next_can_t));
		memset(next_cant_t,0,sizeof(next_cant_t));
	}
	void newstr(string str){
		if(indexof[str])return;
		indexof[str]=++last_part_index;
		stringof[last_part_index]=str;
	}
	//void push_next_can(int cur,int next){
	//	next_can[cur][++next_can]
	//}
}
//arr[s] to arr[t],including start&end
//arr[i]>0,return the end index-after-del;
int remove_same(int *arr,int s,int t){
	sort(arr+s,arr+t+1);
	for(int i=max(s,1);i<=t;i++)
		if(arr[i]==arr[i-1])
			arr[i]=-1;
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
	int l[1000];
	freopen("test.in","r",stdin);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>l[i];
	int to=remove_same(l,1,n);
	for(int i=1;i<=to;i++){
		cout<<l[i]<<" ";
	}
	return 0;
}
