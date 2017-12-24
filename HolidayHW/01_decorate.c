#include <stdio.h>

typedef struct decor{
	char shape;
	float size;
} decoration_t;

decoration_t best_ball(decoration_t *decorations){
	int i = 0;
	while(decorations[i].shape != 'B' && decorations[i].size <= 5) ++i;
	return decorations[i];
}


