#include <stdio.h>

typedef struct decor{
	char shape;
	float size;
} decoration_t;

decoration_t best_ball(decoration_t *decorations);

int main(){
	decoration_t decorations[] = {{'C', 2}, {'C', 3}, {'B', 5}, {'O', 7}, {'C', 6}, {'B', 7}, {'C', 2}, {'O', 1}, {'B', 8}, {'O', 11}};
	printf("Best ball is %.2f big\n", best_ball(decorations).size);
	return 0;
}

decoration_t best_ball(decoration_t *decorations){
	int i = 0;
	while(decorations[i].shape != 'B' || decorations[i].size <= 5) ++i;
	return decorations[i];
}


