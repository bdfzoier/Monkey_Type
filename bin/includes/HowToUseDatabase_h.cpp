#include "database.h"
int main(){
	word_chain fk;
	string s="haha";
	string s2="hello";
	string s3="ltt";
	fk.push_next(s,s2);
	fk.push_next(s,s2);
	fk.push_next(s,s3);
	fk.print();
	puts("-----------------------------------------------------");
	fk.clean(1,2);
	fk.print();
	fk.freespace();//解除空间占用
	return 0;
}
