#include<stdio.h>
#include<stdlib.h>
void comb(int*,int,int);
void print(int*, int);

int main(){
	int a[] = {1,2,3,4};
	comb(a,0,4);
	return 0;
}

void print(int *a, int len){
	for(int i=0;i<len;++i)printf("%d", a[i]);
	printf("\n");
}
void comb(int *a,int start,int len){
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
