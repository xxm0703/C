#include <stdio.h>

struct decoration_t{
	int size;
	char shape;
};

struct decoration_t best_ball(struct decoration_t decor[10]){
	for(int i = 0; i < 10; i++){
		if(decor[i].shape == 'B' && decor[i].size > 5){
			return decor[i];
		}
	}
}


