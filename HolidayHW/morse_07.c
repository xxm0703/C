#include <stdio.h>

void to_morse(char *);

int main(int argc, char **argv){
	for(int i = 1; i < argc; ++i)
		to_morse(argv[i]);
}

void to_morse(char *str){
	char *morse_code[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.",
						"....", "..", ".---", "-.-", ".-..", "--", "-.",
						"---", ".--.", "--.-", ".-.", "...", "-", "..-",
						"...-", ".--", "-..-", "-.--", "--.."};
	while(*str){
		printf("%s ", morse_code[*str-'a']);
		str++;
	}
	printf("\n");
}
