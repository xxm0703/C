#include <stdio.h>

int main(){
	int *add, val;
	scanf("%d %d", add, &val);
	*add = val;
	printf("%d", *add);
	
	return 0;
}







