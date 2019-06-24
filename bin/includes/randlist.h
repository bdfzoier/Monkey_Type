#ifndef DATABASE_H
#define DATABASE_H 1

#include<algorithm>
#include<ctime>

#define NR 100000

struct arr_val{
	int value,prop;
	arr_val(){
		value=-1;
		prop=0;
	}
};
struct prop_arr{
	arr_val l[NR];
	int t,prop_prefix[NR];
	prop_arr(){
		srand(time(NULL));
		t=0;
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
	void print(){
		for(int i=1;i<=t;i++)
			printf("%d,%d ",l[i].value,l[i].prop);
	}
	int rand_gen(bool *used){
		prop_prefix[t+1]=0;
		for(int i=t;i>=1;i--)
			prop_prefix[i]=prop_prefix[i+1]+(used[l[i].value]?0:l[i].prop);
		int ans=-1;
		for(int i=1;i<=t;i++){
			if(used[l[i].value])continue;
			if((rand()%prop_prefix[1])<prop_prefix[i])
				ans=l[i].value;
		}
		return ans;
	}
};

#undef NR

#endif
