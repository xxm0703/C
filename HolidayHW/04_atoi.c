#include <stdio.h>

int to_integer(char *);

int main(int argc, char **argv){
	int sum = 0;
	for(int i = 1; i < argc; ++i) 
		sum += to_integer(argv[i]);
	printf("%d\n", sum);
}

int to_integer(char *str){
	int num = 0;
	do{
		num = num * 10 + *str - '0';
	}while(*++str != '\0');
	return num;
}
