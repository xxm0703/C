#include<stdio.h>

int NOD(int n,int i){
	if(!(n%i))return i;
	return NOD(n,i+1);
}
int main(){
	int i=2,n;
	scanf("%d", &n);
	printf("%d\n",NOD(n,i));

	return 0;
}






