int string_compare(char *str1, char *str2){
	while(*str1++ == *str2++)
		if(*str1 == '\0') return 0;
	if(*str1 > *str2) return -1;
	return 1;
}
