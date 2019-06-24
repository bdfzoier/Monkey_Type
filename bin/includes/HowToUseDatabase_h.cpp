#include "database.h"
int main(){
	freopen("test.txt","r",stdin);
	//fclose(stdin);
	word_chain fk;
	int n;
	scanf("%d",&n);
	while(n--)fk.input();
	//cout<<"ok";
	//freopen("out.txt","w",stdout);
	fk.startrand(5,7,10,1,100);
	fk.freespace();
	freopen("CON", "r", stdin);
	system("pause");
	return 0;
}
