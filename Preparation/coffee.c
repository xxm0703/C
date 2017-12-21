#include <stdio.h>

typedef struct coffee_t{
	float coffee, water;
} coffee_shot_t;

typedef struct coffee_shop_t{
	coffee_shot_t coffes[10];
	int count;
} coffee_shop_t;

int is_espresso(coffee_shot_t coff){
	return (coff.coffee >= 6.5 && coff.water <= 30);
}

int count_espressos(coffee_shop_t shop){
	int count = 0;
	for(int i = 0; i < shop.count; ++i) count += is_espresso(shop.coffes[i]);
	return count;
}

int add_coffee(coffee_shop_t *shop, coffee_shot_t coff){
	if(shop->count < 10){ 
		shop->coffes[shop->count-1] = coff;
		shop->count++;
		return 1;
	}
	return 0;
}

void print_coffee(coffee_shop_t shop){
	for(int i = 0; i < shop.count; ++i) printf("%d\t%.1f-%.1f\n", is_espresso(shop.coffes[i]), shop.coffes[i].coffee, shop.coffes[i].water);
}

int main(){
	coffee_shop_t shop;
	for(int i = 0; i < 4; ++i){
		scanf("%f", &shop.coffes[i].coffee);
		scanf("%f", &shop.coffes[i].water);
		shop.count = i + 1;
	}
	print_coffee(shop);
	return 0;
}
