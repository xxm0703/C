#include "vector.h"
#include <stdlib.h>
#include <stdio.h>

int main(){
	tire_stand_t stand;
	stand = read_tires();
	print_mountainbike_tires(stand);
	printf("%f\n", get(filter_non_mountainbikes(stand), 1).weight);
	return 0;
}
