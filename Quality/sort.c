#include<stdio.h>
#include<stdlib.h>

void sort(int *, int);

int main(int argc, char **argv){
	int arr[argc];
	for(int i = 1; i < argc; ++i) arr[i] = atoi(argv[i]);
	sort(arr, argc);
	for(int i = 0; i < argc-1; ++i) printf("%d ", arr[i]);
}

void sort(int *arr, int len){
	for(int i = 0; i < len; ++i){
		int max = i;
		for(int j = i; j < len; ++j){
			if(arr[max] < arr[j]){
				int tmp = arr[max];
				arr[max] = arr[j];
				arr[j] = tmp;
			}
		}
	}
}



