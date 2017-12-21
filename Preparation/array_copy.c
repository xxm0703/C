#include <stdio.h>

void array_copy(int *, int *, int);
void print_bytes(char *, int);
int count(char *, int(*predict)(char));
int filter(int *, int, int (*predict)(int));
int big(int a){
	return a > 4;
}

int main(){
	int arr[] = {12, 5, 2, 4, 12, 1, 6};
	for(int i = 0; i < 7; ++i) printf("%d ", arr[i]);
	printf("\n");
	filter(arr, 7, big);
	for(int i = 0; i < 7; ++i) printf("%d ", arr[i]);
	return 0;
}

int filter(int *arr, int count, int (*predict)(int)){
	int len = count-1;
	for(int i = 0; i < count; ++i){
		int tmp;
		if(!predict(arr[i])){
			int tmp = arr[i];
			array_copy(arr+i+1,arr+i,--count);
			arr[len] = tmp;
			i--;
		}
	}
	return count;
}

int count(char *str, int(*predict)(char)){
	int counter = 0;
	for(int i = 0; str[i] != '\0'; ++i)
		if(predict(str[i]))
			++counter;
	return counter;
}

void print_bytes(char *src, int count){
	for(int i = 0; i < count; ++i) printf("%p ", (src+i));
}

void array_copy(int *src, int *dst, int count){
	while(count--) *dst++ = *src++;
}
