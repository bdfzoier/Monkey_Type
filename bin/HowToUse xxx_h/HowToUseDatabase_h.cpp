#include "database.h"
int main(){
	word_chain fk;
	string s="haha";
	string s2="fuck";
	string s3="kiafuha";
	fk.push_next(s,s2);
	fk.push_next(s,s2);
	fk.push_next(s,s3);
	fk.print();
	puts("-----------------------------------------------------");
	fk.clean(1,2);
	fk.print();
	return 0;
}
