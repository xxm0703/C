#include <stdio.h>

void print_element(int);
void for_each(int *, int, void (*print_el)(int));
void multiply(int);

int main(){
	int arr[] = {18,2,94,4,15,6,31};
	for_each(arr, 7, print_element);
	for_each(arr, 7, multiply);
	return 0;
}
void print_element(int index){
	printf("%d\n", index);
}

void for_each(int *arr, int size, void (*print_el)(int)){
	for(int i = 0; i < size; ++i){
		print_el(arr[i]);
	}
}

void multiply(int a){
	printf("%d\n", a*2);
}
