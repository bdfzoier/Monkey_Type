#include<iostream>
#include<cstdio>
using namespace std;
//是否是元音
inline bool is_vowel(char x){
	char vowel[6]="aeiou";
	for(int i=0;i<5;i++)
		if(x==vowel[i])return 1;
	return 0;
}
//分离元音组和辅音组
int sep(string str,string* after_sep/*分组后存储数组*/){
	//字符串指针
	int t=0;
	int after_t=0;
	//每一部分循环一次
	int len=(int)str.length();
	while(t<len){
		string cur;
		if(is_vowel(str[t])){
			//记录该部分的开始下标
			int savet=t;
			while(is_vowel(str[t])&&t<len)t++;
			cur.assign(str,savet,t-savet);
		}
		else{
			//记录该部分的开始下标
			int savet=t;
			while(!is_vowel(str[t])&&t<len)t++;
			cur.assign(str,savet,t-savet);
		}
		after_sep[after_t]=cur;
		after_t++;
	}
	//返回部分数
	return after_t;
}
int main(){
	string s;
	string af[100];
	cin>>s;
	int to=sep(s,af);
	for(int i=0;i<to;i++)cout<<af[i]<<" ";
	return 0;
}
