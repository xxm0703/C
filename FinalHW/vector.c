#include "vector.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>


bike_tire_t get(tire_stand_t s, int index) {
    return s.tires[index];
}

int size(tire_stand_t s) {
    return s.count;
}

int full(tire_stand_t s) {
    return s.count >= s.size;
}

tire_stand_t filter_non_mountainbikes(tire_stand_t s){
	tire_stand_t stand = init();
	for(int i = 0; i < size(s); ++i)
		if(!is_for_mountainbike(get(s, i)))
			push_back(&stand, get(s, i));
	return stand;
}

int is_for_mountainbike(bike_tire_t tire){
	if(tire.diameter == 26 || tire.diameter == 27.5 || tire.diameter == 29)
		if(tire.weight >= 1.7 && tire.min_press < 2)
			return 1;
	return 0;
}

tire_stand_t read_tires(){
	tire_stand_t stand = init();
	printf("Space separate input ending with EOF: diameter weight min_pressure max_pressure\n");
	bike_tire_t tire;
	char s[20];
	while(fgets(s, 20, stdin)){
		tire.diameter = atof(strtok(s, " \n"));
		tire.weight = atof(strtok(NULL, " \n"));
		tire.min_press = atof(strtok(NULL, " \n"));
		tire.max_press = atof(strtok(NULL, " \n"));
		push_back(&stand, tire);
	}
	return stand;
}

void print_mountainbike_tires(tire_stand_t stand){
	for(int i = 0; i < size(stand); ++i){
		if(is_for_mountainbike(get(stand, i)))
			printf("Diameter: %.2f Weight: %.2f Min pressure: %.2f\n", 
stand.tires[i].diameter, stand.tires[i].weight, stand.tires[i].min_press);		
	}
}

void push_back(tire_stand_t *s, bike_tire_t tire) {
	if(full(*s)){	    
		s->size *= 2;	
	
		s->tires = realloc(s->tires, sizeof(bike_tire_t) * s->size);

	}
    s->tires[s->count++] = tire;
}

void destroy(tire_stand_t *s) {
    s->size = 0;
	s->count = 0;

    free(s->tires);

    s->tires = NULL;
}

tire_stand_t init(){
	tire_stand_t s = {malloc(sizeof(bike_tire_t)), 0, 1};	
	return s;
}

