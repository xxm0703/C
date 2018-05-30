#include<stdio.h>
#include<stdlib.h>

int rightmost_one(int n){
	if(!n) return 0;
	int i = 1;
	while(!(n % 2)){
		n >>= 1;
		i++;
	}
	return i;
}

int main(int argc, char **argv){
	printf("%d\n", rightmost_one(atoi(argv[1])));
	return 0;
}

