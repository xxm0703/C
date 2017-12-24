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
	int better;
	for(int i = 0; i < n; ++i) bottles[i] = atoi(argv[i+2]);
	for(int year = 1; year <= n; ++year){
		if(bottles[right] < bottles[left]) better = right--;
		else better = left++;
		sum += bottles[better] * year;
		printf("Selling bottle %d for %d\n", better, bottles[better] * year);
	}
	printf("Money: %d\n", sum);
	return 0;
}


