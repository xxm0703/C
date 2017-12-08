#include <stdio.h>
#include <stdlib.h>

typedef struct cake_t{
	int icing;
	float kcal;
} cake;

void print_cake(cake*);
void add_icing(cake *);
void for_each_cake(cake**, int, void(*add)(cake*));

int main(){
	cake *torti[5];
	for(int i = 0; i < 5; ++i){
		torti[i] = malloc(sizeof(cake));
		scanf("%d %f", &torti[i]->icing, &torti[i]->kcal);
	}
	for_each_cake(torti, 5, print_cake);
	for_each_cake(torti, 5, add_icing);
	printf("\n");
	for_each_cake(torti, 5, print_cake);	
	return 0;
}
void add_icing(cake *torta){
	if(!torta->icing){
		torta->icing = 1;
		torta->kcal += 1.5;
	}
}

void print_cake(cake* torti){
	cake *c = torti;
	printf("kcal: %.2f icing:%d\n", c->kcal, c->icing);
}

void for_each_cake(cake** torti, int size, void(*add)(cake*)){
	for(int i = 0; i < size; ++i){
		add(torti[i]);
	}
}
