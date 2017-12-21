#include <stdio.h>
#include <string.h>

int word_count(char*, char*);
void reverse(char*);
int is_palindrome(char*);
int main(){
	char str[] = "I need to be reversed,now!";
	printf("%s\n", str);
	reverse(str);
	printf("%s\n", str);
	printf("%d\n", is_palindrome(str));	
	printf("%d\n", word_count(str, " ,"));
	return 0;
}
int word_count(char *str, char *sep){
	int count = 1; 
	strtok(str, sep);
	while(strtok(NULL, sep)) ++count;
	return count;
}
int is_palindrome(char *str){
	char str1[30];
	strcpy(str1, str);
	reverse(str);
	if(!strcmp(str, str1)) return 1;
	return 0;
}
void reverse(char *str){
	char tmp;
	int size = strlen(str);	
	for(int i = 0; i < size/2; ++i){
		tmp = str[i];
		str[i] = str[size-i-1];
		str[size-i-1] = tmp;
	}
}
