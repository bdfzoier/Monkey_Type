#ifndef DATABASE_H
#define DATABASE_H 1

#include<algorithm>
#include <ctime>

#define NR 100000

struct arr_val{
	int value,prop;
	arr_val(){
		value=-1;
		prop=0;
	}
};
struct prop_arr{
	arr_val *l;
	int lft[NR], rgt[NR], sum;
	int t;
	prop_arr(){
		t=0;
		l=new arr_val[NR];
	}
	void mk(int *x,int len){
		std::sort(x+1,x+len+1);
		int cnt=0;
		for(int i=len;i>=1;i--){
			if(x[i]==x[i-1] && (i>=1))
				cnt++;
			else{
				l[++t].value=x[i];
				l[t].prop=cnt+1;
				cnt=0;
			}
		}
	}
	//use this before using GETRANDOM(), else the GETRANDOM function will run into problems.
	arr_val RandomPrefix() {
		rgt[0] = -1;
		std::srand(unsigned(std::time(NULL)));
		for (int i = 1;i <= t;i++) {
			lft[i] = rgt[i - 1] + 1;
			rgt[i] = lft[i] + l[t].prop - 1;
			sum += l[t].prop;
		}
	}
	arr_val GetRandom() {
		int k = (rand() % 3000) * (rand() % 3000) % sum;
		int idx = lower_bound(lft, lft + t, k) - l;
		return l[idx];
	}
	void print(){
		for(int i=1;i<=t;i++)
			printf("%d,%d ",l[i].value,l[i].prop);
	}
};

#undef NR

#endif
