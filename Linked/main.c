#include"list.h"
#include"stdio.h"
#undef remove

int main(){
	list_t l = init_list(8);
	insert(&l, 3);
	insert_after(&l, 4, 0);
	printf("%d %d %d", l.head->value, l.head->next->value, l.head->next->next->value);
	return 0;
}



