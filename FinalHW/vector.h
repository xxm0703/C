#ifndef __VECTOR_H__
#define __VECTOR_H__

typedef struct bike_tire_t{
	float diameter, weight, min_press, max_press;
} bike_tire_t;

typedef struct tire_stand_t{ 
	bike_tire_t *tires; 
	int count, size; 
} tire_stand_t; 

int size(tire_stand_t);
int full(tire_stand_t);
void destroy(tire_stand_t*);
bike_tire_t get(tire_stand_t, int);
void push_back(tire_stand_t*, bike_tire_t);
tire_stand_t filter_non_mountainbikes(tire_stand_t);
int is_for_mountainbike(bike_tire_t tire);
void print_mountainbike_tires(tire_stand_t stand);
tire_stand_t read_tires();
tire_stand_t init();

#endif
