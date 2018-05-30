#include<stdio.h>

typedef struct hero_t{
	float max_hp, hp, dmg, def;
} hero_t;

float hero_power(hero_t);
int can_attend_instance(int, hero_t *, int);

int main(){
	hero_t h1 = {100, 76, 28, 16};
	printf("Hero with %.2f max hp, %.2f damage, %.2f defence and power %.2f\n", 
h1.max_hp, h1.dmg, h1.def, hero_power(h1));
	return 0;
}

float hero_power(hero_t hero){
	return hero.dmg + hero.max_hp +hero.def;
}

int can_attend_instance(int min_power_required, hero_t *heros, int heros_count){
	for(int i = 0; i < heros_count; ++i){
		if(heros[i].hp < heros[i].max_hp / 2 || hero_power(heros[i]) < min_power_required) 
			return 0;
	}
	return 1;
}

