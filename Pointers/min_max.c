#include <stdio.h>


void min_max(int *arr, int size, int *min, int *max);
int main(){
	int arr[] = {13,2,30,4,1,5,6};
	int golqmo, malko;
	min_max(arr,7,&malko, &golqmo);
	printf("MIN: %p - %d", (void*)(&malko), malko);
	printf("MAX: %p - %d", (void*)(&golqmo), golqmo);	
	return 0;
}

void min_max(int *arr, int size, int *min, int *max){
	*max = arr[0];
	*min = arr[0];
	for(int i = 0; i < size; ++i){
		printf("%d - %d\n", *max, arr[i]);
		if(*min > arr[i]) *min = arr[i];
		if(*max < arr[i]) *max = arr[i];
	}
}
