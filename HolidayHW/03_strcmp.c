#include <stdio.h>

int string_compare(char *, char *);

int main(){
	char str1[] = "strcmp";	
	char str2[] = "strcmp";
	printf("%s == %s - %d\n", str1, str2, string_compare(str1,str2));
	str1[3] = 'k';
	printf("%s == %s - %d\n", str1, str2, string_compare(str1,str2));
	str1[3] = 'a';
	printf("%s == %s - %d\n", str1, str2, string_compare(str1,str2));
	return 0;
}

int string_compare(char *str1, char *str2){
	while(*str1++ == *str2++)
		if(*str1 == '\0') return 0;
	if(*(str1-1) < *(str2-1)) return -1;
	return 1;
}
