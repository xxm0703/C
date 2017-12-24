#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//#include "04_atoi.c"


int main(int argc, char **argv){
	int right,sum = 0, left = 0;
	int n = atoi(argv[1]);
	right = n - 1;
	assert(n == argc-2);
	int bottles[n];
	for(int i = 0; i < n; ++i) bottles[i] = atoi(argv[i+2]);
	for(int k = 1; k <= n; ++k){
		if(bottles[right] < bottles[left]) sum += bottles[right--] * k;
		else sum += bottles[left++] * k;
	}
	printf("Money: %d\n", sum);
	return 0;
}


