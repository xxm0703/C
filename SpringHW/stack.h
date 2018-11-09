typedef struct stack_t{
    int *array, capacity;
}stack_t;

void push(stack_t *, int);
int pop(stack_t *);
stack_t init();