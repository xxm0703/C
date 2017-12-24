#include <stdio.h>

typedef struct barbaron{
	char type, size;
	int cost;
} barbaron_t;


typedef struct barbaron_shop{
	barbaron_t barbarons[10];
	int index;
} barbaron_shop_t;

void add_barbaron(barbaron_shop_t *, barbaron_t);
barbaron_t buy_barbaron(barbaron_shop_t *, char, char, int *);
void print_barbaron(barbaron_t);
void print_barbaron_shop(barbaron_shop_t);

int main(){
	int costs[] = {11, 9, 25, 93, 17, 5}; // For simplicity of the user input
	barbaron_shop_t shop;
	shop.index = 0;
	barbaron_t tmp; // Helpful var
	for(int i = 0; i < 6; ++i){
		tmp.cost = costs[i];
		scanf("%c %c", &tmp.type, &tmp.size);
		getchar();
		shop.barbarons[shop.index++] = tmp;
	}
	print_barbaron_shop(shop);
	tmp = (barbaron_t){'P', 'M', 13}; // The casting is so i can make it on 1 line
	add_barbaron(&shop, tmp);
	printf("After adding new barbaron:\n");
	print_barbaron_shop(shop);
	printf("Buying barbaron P of size M with 43 coins:\n");
	int money = 43;
	print_barbaron(buy_barbaron(&shop, 'P', 'M', &money));
	printf("Coins left => %d\n", money);
	return 0;
}

void print_barbaron_shop(barbaron_shop_t shop){
	for(int j = 0; j < shop.index; j++){
		printf("%d. ", j+1);	// For easy counting
		print_barbaron(shop.barbarons[j]);
	}
}

void print_barbaron(barbaron_t bar){
	printf("Cost: %-3d"
			"Size: %-3c"
			"Type: %-3c\n", bar.cost, bar.size, bar.type);
}

void add_barbaron(barbaron_shop_t *shop, barbaron_t barbaron){
	if(shop->index < 10) shop->barbarons[shop->index++] = barbaron;
}

barbaron_t buy_barbaron(barbaron_shop_t *shop, char type, char size, int *money){
	int i;
	for(i = 0; i < shop->index; ++i){
		barbaron_t bar = shop->barbarons[i];
		if(bar.type == type && bar.size == size && bar.cost < *money){
			*money -= bar.cost;
			return bar;
		}
	}
	return shop->barbarons[i]; // Defaut case
}


