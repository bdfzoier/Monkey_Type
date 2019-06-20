#include "database.h"
int main(){
	freopen("test.txt","r",stdin);
	word_chain fk;
	int n;
	cin>>n;
	while(n--){
		fk.input();
	}
	freopen("out.txt","w",stdout);
	//puts("-------------");
	for(int i=1;i<=fk.last_part_index;i++)
		fk.clean(i,30);
	fk.startdfs(7,1);
	fk.freespace();
	return 0;
}
