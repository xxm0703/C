#include <stdio.h>

typedef struct card_t{
	int num;
	float money;
} card_t;

int pay_with(card_t *, float);

int main(){
	card_t credit = {110, 3295};
	printf("%.2f\n", credit.money);
	pay_with(&credit, 215.63);
	printf("%.2f\n", credit.money);
	return 0;
}

int pay_with(card_t *card, float transfer){
	if(card->money >= transfer){
		card->money -= transfer;
		return 1;
	}
	return 0;
}
