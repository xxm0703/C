#include<stdio.h>
#include<stdlib.h>
#include<math.h>

typedef struct vector_t{
	int x,y;
} vector_t;

float lenght(vector_t v);

int main(int argc, char **argv){
	if(!argc%2) return 1;
	vector_t vec;

	for(int i = argc-2; i > 0; i-=2){
		vec.x = atoi(argv[i]);
		vec.y = atoi(argv[i+1]);
		printf("%.2f ", lenght(vec));
	}

	return 0;
}

float lenght(vector_t v){
	return sqrt(pow(v.x, 2) + pow(v.y, 2));
}
