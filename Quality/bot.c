#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct order_t{
	char addr[50], name[20], number[13];
	int pizz;
}order_t;

void get_addr(char *str){
	printf("\nPlease tell me your address: ");
	scanf("%s", str);
}

int get_pizza(){
	char pizzas[][20] = {"BBQ", "American Hot", "Burger"};
	int index;
	for(int i = 1; i <= 3; ++i) printf("%d %s\n", i, pizzas[i-1]);
	scanf("%d", &index);
	return index;
}

order_t get_info(order_t or){
	char param[20];
	printf("Name or Number: ");
	scanf("%s", param);
	if(atoi(param))strcpy(or.number, param); 
	else strcpy(or.name, param);
	printf("Other: ");
	scanf("%s", param);
	if(atoi(param))strcpy(or.number, param); 
	else strcpy(or.name, param);
	return or;
}

order_t full_order(){
	order_t ord, or;
	printf("Hi, i'm the 'Pizza Bot'...");
	get_addr(ord.addr);	
	ord.pizz = get_pizza();
	or = get_info(ord);
	strcpy(ord.name, or.name);
	strcpy(ord.number, or.number);
	return ord;
}
int main(){
	order_t ord;
	ord = full_order();
	printf("%s\n", ord.name);
	printf("%s\n", ord.number);
	printf("%s\n", ord.addr);
	printf("%d\n", ord.pizz);
	return 0;
}
