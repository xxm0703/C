#include<stdio.h>

typedef struct chair_t{
	float cost, weight;
	int is_leather;
} chair_t;

void apply_discount(chair_t *chairs, int chairs_count){
	for(int i = 0; i < chairs_count; ++i){
		if(chairs[i].is_leather) chairs[i].cost *= 41.0/50;
		else chairs[i].cost *= 4.0/5;
	}
}

struct chair_t pick_chair(int person_weight, chair_t *chairs, int chairs_count){
	chair_t *best = NULL;
	for(int i = 0; i < chairs_count; ++i){
		if(chairs[i].weight > person_weight){
			if(!best || chairs[i].is_leather > best->is_leather || best->cost < chairs[i].cost)
				best = chairs + i;
		}
	}
	return *best;
}

int main(){
	chair_t c1 = {25, 150, 1};
	printf("Chair costs - %.2f, max weight - %.2f and is leather - %d\n", c1.cost, c1.weight, c1.is_leather);
	apply_discount(&c1, 1);
	printf("After discount, cost = %.2f\n", c1.cost);
	return 0;
}


