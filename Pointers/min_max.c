#include <stdio.h>

void print(int *arr, int size);
void min_max(int *arr, int size, int *min, int *max);
void find_replace(int *arr, int size, int find, int replace);
int main(){
	int arr[] = {13,2,30,4,1,5,6};
	int malko, golqmo;
	min_max(arr,7,&malko, &golqmo);
	print(arr, 7);
	find_replace(arr, 7, malko, golqmo);
	print(arr, 7);
	printf("MIN: %p - %d\n", (void*)(&malko), malko);
	printf("MAX: %p - %d\n", (void*)(&golqmo), golqmo);	
	return 0;
}

void print(int *arr, int size){
	for(int i = 0; i < size; ++i){
		printf("%d ", arr[i]);
	}	
	printf("\n");
}

void find_replace(int *arr, int size, int find, int replace){
	for(int i = 0; i < size; ++i){
		if(arr[i] == find)arr[i] = replace;
	} 
}
void min_max(int *arr, int size, int *min, int *max){
	for(int i = 0; i < size; ++i){
		if(*min > arr[i]) *min = arr[i];
		else if(*max < arr[i]) *max = arr[i];
	}
}
