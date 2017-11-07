#include<stdio.h>
void comb(char*,int,int);
void print(char*, int);
int main(){
	char a[] = "abc";
	comb(a,0,3);
	return 0;
}
void print(char a[], int len){
	for(int i=0;i<len;++i)printf("%c", a[i]);
	printf("\n");
}
void comb(char a[],int start,int len){
	if(start == len-1) print(a,len);
	else for(int i = start;i < len; ++i){
		char tmp = a[i];
		a[i] = a[start];
		a[start] = tmp;
		comb(a,start+1,len);
		a[start] = a[i];
		a[i] = tmp;
	}	
}
