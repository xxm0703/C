#ifndef LIST_T
#define LIST_T

typedef struct node_t{
	int value;
	struct node_t *next;
} node_t;

typedef struct list_t{
	node_t *head;
} list_t;

extern list_t init_list(int);
extern void destroy(list_t *);
extern int size(list_t);
extern int empty(list_t);
extern list_t copy(list_t);
extern void insert_first(list_t *, int);
extern void remove_first(list_t *);
extern void insert_after(list_t *, int, int);
extern void remove_after(list_t *, int);
extern int get(list_t, int);


#endif
