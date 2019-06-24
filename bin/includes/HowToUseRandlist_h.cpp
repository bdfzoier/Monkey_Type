    
#include<iostream>
#include<cstring>
#include<cstdio>
#include "randlist.h"
using namespace std;
prop_arr my;
int h[100];
bool vis[100];
int main(){
	freopen("test.in","r",stdin);
	int  n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",h+i);
	my.mk(h,n);
	my.print();
	printf("\n");
	int s[100];
	vis[1]=1;
	memset(s,0,sizeof(s));
	for(int i=1;i<10000;i++)
		s[my.rand_gen(vis)]++;
	cout<<s[2]<<" "<<s[3]<<" "<<s[4];
	return 0;
}
