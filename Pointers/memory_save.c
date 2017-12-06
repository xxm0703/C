#include <stdio.h>

int main(){
	int *add = NULL;
	int val;
	scanf("%d %d", add, &val);
	*add = val;
	printf("%d", *add);
	
	return 0;
}







