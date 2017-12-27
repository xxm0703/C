#include <stdio.h>
#include <string.h>

typedef struct tag_t {
	char name[10];
	int self_closing;
	struct tag_t *child;
} tag_t;

void add_child(tag_t *, char[15], int);
void print_markup(tag_t);
char *get_tag(tag_t *, char *);

int main(){
	tag_t body = {"body", 1, NULL};
	tag_t html = {"html", 0, NULL};
	print_markup(body);
	print_markup(html);
	add_child(&html, "br", 1);
	print_markup(html);
	return 0;
}

void add_child(tag_t *parent, char name[15], int is_self_closing){
	strcpy(parent->child->name, name);	
	parent->child->self_closing = is_self_closing;
	parent->child->child = NULL;
}


void print_markup(tag_t object){
	char str[100];
	*str = '\0';
 	printf("%s\n", get_tag(&object, str));
}

char *get_tag(tag_t *tag, char *str){
	if(tag->self_closing){
		strcat(str, "</");
		strcat(str, tag->name);
		strcat(str, ">");
	}else{
		strcat(str, "<");
		strcat(str, tag->name);
		strcat(str, ">");
		strcpy(str, (tag->child ? get_tag(tag->child, str) : str));
		strcat(str, "</");
		strcat(str, tag->name);
		strcat(str, ">");
	}
	return str;
}

