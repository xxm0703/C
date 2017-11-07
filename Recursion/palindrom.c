#include<stdio.h>

int palin(char*,int,int);

int main(){
	printf("%d\n", palin("bob",0,3));
	printf("%d\n", palin("manm",0,4));
	printf("%d\n", palin("bobob",0,5));
	printf("%d\n", palin("bobbob",0,6));
	printf("%d\n", palin("bobi",0,4));
	return 0;
}
int palin(char str[],int index,int size){
	if(index>=size-1-index)return 1;
	return str[index]==str[size-index-1] && palin(str,index+1,size);
}
