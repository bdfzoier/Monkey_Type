#include "database.h"
int main(){
	freopen("test.txt","r",stdin);
	//fclose(stdin);
	word_chain fk;
	int n;
	scanf("%d",&n);
	while(n--)fk.input();
	//cout<<"ok";
	freopen("gen.txt","w",stdout);
	fk.startrand(1,7,1000,1,1000);
	fk.freespace();
	//freopen("CON", "r", stdin);
	//system("pause");
	return 0;
}
