#include"list.h"
#include"stdio.h"

int main(){
	list_t l = init_list(8);
	insert_first(&l, 3);
	insert_after(&l, 4, 0);
	list_t l2 = copy(l);
	printf("%d %d %d\n", l.head->value, l.head->next->value, l.head->next->next->value);
	remove_first(&l);
	printf("Index 1: %d Size: %d Empty: %d\n", get(l, 1), size(l), empty(l));
	remove_after(&l, 0);
	printf("%d %d %d\n", l2.head->value, l2.head->next->value, l2.head->next->next->value);
	printf("l: %d\n", l.head->value);
	destroy(&l);
	destroy(&l2);
	return 0;
}



