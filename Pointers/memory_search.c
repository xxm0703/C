#include <stdio.h>

int main(){
	int num;
	int *var = &num;
	*var = 50;
	int **ptr = &var;
	printf("%p\n", (void*)&var);
	printf("%p\n", (void*)&ptr);
	printf("%d\n", *var);
	printf("%p\n", (void*)*ptr);
	return 0;
}
