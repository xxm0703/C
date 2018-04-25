#include"list.h"
#include<stdlib.h>

list_t init_list(int value){
	list_t l;
	l.head = malloc(sizeof(node_t));
	l.head->value = value; 
	l.head->next = NULL;
	return l;
}

void destroy(list_t *l){
	node_t *tmp = l->head;
	while(l->head){
		l->head = l->head->next;
		free(tmp);
		tmp = l->head;
	}
}

int size(list_t l){
	int count = 1;
	while(l.head->next){
		l.head = l.head->next;
		count++;
	}
	return count;	
}

int empty(list_t l){
	return l.head == NULL;
}

list_t copy(list_t l){
	list_t new_list = init_list(l.head->value);
	node_t *tmp = new_list.head;
	while(l.head->next){
		tmp->next = malloc(sizeof(node_t));
		tmp = tmp->next;
		l.head = l.head->next;
		tmp->value = l.head->value;
	}
	tmp->next = NULL;
	return new_list;
}

void insert_first(list_t *l, int value){
	node_t *node = malloc(sizeof(node_t));
	node->value = value;
	node->next = l->head;
	l->head = node;
}

void remove_first(list_t *l){
	node_t *node = l->head;
	l->head = l->head->next;
	free(node);
}

void insert_after(list_t *l, int value, int index){
	node_t *marker = l->head;
	while(index-- && l->head) marker = marker->next;
	node_t *node = malloc(sizeof(node_t));
	node->value = value;
	node->next = marker->next;
	marker->next = node;	
}

void remove_after(list_t *l, int index){
	node_t *marker = l->head;
	while(index-- && l->head) marker = marker->next;
	node_t *node = marker->next;
	marker->next = marker->next->next; 
	free(node);
}

int get(list_t l, int index){
	while(index-- && l.head) l.head = l.head->next;
	return l.head->value;
}

