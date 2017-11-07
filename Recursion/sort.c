#include<stdio.h>
int max(int*, int);
void print(int a[], int len){
	for(int i=0;i<len;++i)printf("%d", a[i]);
	printf("\n");
}
void sort(int*, int);
void swap(int*, int a, int b);
int main(){
	int a[] = {4,5,2,8,1,67,78,34,21,12};
	print(a,10);
	sort(a,10);
	print(a,10);
	return 1;
}

int max(int a[],int size){
	if(size == 1)return 0;
	int tmp = max(a,size-1);
	if(a[size-1] > a[tmp])return size-1;
	return tmp;
}
void swap(int arr[], int a, int b){
	int tmp = arr[a];
	arr[a] = arr[b];
	arr[b] = tmp; 
}

void sort(int a[], int size){
	swap(a,size-1,max(a,size));
	if(size > 1)sort(a, size-1);
}
