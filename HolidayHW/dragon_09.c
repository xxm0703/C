#include<stdlib.h>
#include<stdio.h>
#include<time.h>


typedef struct hero_t hero_t; 
typedef struct dragon_t dragon_t;
struct dragon_t{
	int hp[3];
	void (*strike)(struct hero_t*);
};

struct hero_t{
	int hp;
	void (*strike)(dragon_t*, int);
};

int random(int);
dragon_t init_dragon(int, void (*func)(hero_t *));
void hero_strike(dragon_t *, int);
void dragon_strike(hero_t *);

int main(){
	srand(time(NULL));
	hero_t hero = {100, &hero_strike};
	dragon_t dragon = init_dragon(75, &dragon_strike);
	int current_head = 0;
	while(hero.hp > 0 && dragon.hp[2] > 0){
		if(dragon.hp[current_head] <= 0){
			current_head++;
			printf("Head %d is dead!\n\n", current_head);
		}
		dragon.strike(&hero);
		hero.strike(&dragon, current_head);
		printf("\n");
	}
	if(hero.hp <= 0) printf("Hero died! Dragon left at %d HP\n", dragon.hp[current_head]);
	else printf("Dragon died! Hero left at %d HP\n", hero.hp);
	return 0;
}

int random(int n){
	return rand() % n;
}

dragon_t init_dragon(int hp, void (*func)(hero_t *)){
	dragon_t drag;
	for(int i = 0; i < 3; ++i) drag.hp[i] = hp;
	drag.strike = func; 
	return drag;
}

void hero_strike(dragon_t *drag, int head){
	int dmg;
	if(!random(7)){
		dmg = 50;
	}else{
		dmg = random(30)+1;
	}
	drag->hp[head] -= dmg;
	printf("Hero dealed%s Damage %d HP! To head %d.\n", (dmg == 50 ? " Critical" : ""), dmg, head+1);
}

void dragon_strike(hero_t *hero){
	int dmg = random(10)+1;
	hero->hp -= dmg;
	printf("Dragon hit Hero for %d Damage\n", dmg);
}

