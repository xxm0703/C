#include<stdio.h>
#include<stdlib.h>

typedef struct bike_tire_t{
	float diameter, weight, min_press, max_press;
} bike_tire_t;

typedef struct tire_stand_t{
	bike_tire_t *tires;
	int count;
} tire_stand_t;

tire_stand_t read_tires(){
	tire_stand_t stand = {NULL, 0};
	printf("Space separate input: diameter weight min_pressure max_pressure\n");
	bike_tire_t tire;
	while(scanf("%f %f %f %f", &(tire.diameter), &(tire.weight), &(tire.min_press), &(tire.max_press)) == 4){
		stand.tires = realloc(stand.tires, sizeof(bike_tire_t) * ++stand.count);
		stand.tires[stand.count-1] = tire;
	}
}

int is_for_mountainbike(bike_tire_t tire){
	if(tire.diameter == 26 || tire.diameter == 27.5 || tire.diameter == 29)
		if(tire.weight >= 1.7 && tire.min_press < 2)
			return 1;
	return 0;
}

void print_mountainbike_tires(tire_stand_t stand){
	for(int i = 0; i < stand.count; ++i){
		if(is_for_mountainbike(stand.tires[i]))
			printf("Diameter: %.2f Weight: %.2f Min pressure: %.2f\n", 
stand.tires[i].diameter, stand.tires[i].weight, stand.tires[i].min_press);		
	}
}

int main(){
	tire_stand_t stand = read_tires();
	print_mountainbike_tires(stand);
	return 0;
}
