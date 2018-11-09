#include<stdio.h>
int cal(int par){
	if(par <= 10) return 10;
	return cal(par/10) +cal(par/5);
}

int main(){
	printf("%d", cal(200));
	return 0;
}
