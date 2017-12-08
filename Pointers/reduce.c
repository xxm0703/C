#include <stdio.h>

int reduce(int *arr, int size, int(*op)(int, int));
int sum(int, int);

int main(){
	int arr[] = {18,2,73,4,12,69,7};
	printf("%d\n", reduce(arr, 7, sum));
	printf("%d\n", reduce(arr, 6, sum));
	printf("%d\n", reduce(arr+1, 6, sum));
	return 0;
}

int sum(int a, int b){
	return a+b;
}

int reduce(int *arr, int size, int(*op)(int, int)){
	if(size == 1) return *arr;
	return op(reduce(arr,size-1,op), arr[size-1]);
}
