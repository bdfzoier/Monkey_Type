#include<iostream>
#include<cstring>
#include<cstdio>
#include "randlist.h"
using namespace std;
prop_arr my;
int h[100];
int main(){
	//freopen("test.in","r",stdin);
	int  n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",h+i);
	my.mk(h,n);
	my.print();
	printf("\n");
	for(int i=1;i<=n;i++)
		printf("%d",h[i]);
	return 0;
}
