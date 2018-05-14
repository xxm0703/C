#ifndef LIST_T
#define LIST_T

typedef struct node_t{
	int value;
	struct node_t *next;
} node_t;

typedef struct list_t{
	node_t *head;
} list_t;

list_t init_list();
void destroy(list_t *);
void reverse(list_t *);
int size(list_t);
int empty(list_t);
list_t copy(list_t);
void insert_first(list_t *, int);
void remove_first(list_t *);
void insert_after(list_t *, int, int);
void remove_after(list_t *, int);
int get(list_t, int);


#endif
