    
#include<iostream>
#include<cstring>
#include<cstdio>
#include "randlist.h"
using namespace std;
prop_arr my;
int h[100], cnt[100];
int main(){
	//freopen("test.in","r",stdin);
	int  n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",h+i);
	my.mk(h,n);
	my.print();
	putchar('\n');
	my.RandomPrefix();
	for (int i = 1;i <= 100;i++) {
		printf("%d\n", my.GetRandom());
	}
	return 0;
}
