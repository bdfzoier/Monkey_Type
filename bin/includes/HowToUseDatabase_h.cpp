#include "database2.h"
int main(){
	freopen("test.txt","r",stdin);
	word_chain fk;
	int n;
	cin>>n;
	while(n--){
		fk.input();
	}
	freopen("out.txt","w",stdout);
	fk.print();
	puts("-------------");
	for(int i=2;i<=fk.last_part_index;i++)
		fk.clean(i,5);
	fk.print();
	fk.freespace();
	return 0;
}
