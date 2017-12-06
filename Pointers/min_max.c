#include <stdio.h>

void min_max(int *arr, int size, int *min, int *max);
int main(){
	int arr[] = {13,2,30,4,1,5,6};
	int *malko = arr;
	int *golqmo = arr;
	min_max(arr,7,malko, golqmo);
	printf("MIN: %p - %d", (void*)malko, *malko);
	printf("MAX: %p - %d", (void*)golqmo, *golqmo);	
	return 0;
}

void min_max(int *arr, int size, int *min, int *max){
	for(int i = 0; i < size; ++i){
		if(*min > arr[i]) min = arr+i;
		else if(*max < arr[i]) max = arr+i;
	}
}
