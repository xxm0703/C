#include<stdio.h>

typedef struct person_t{
	int knows, helps;
} person_t;

int ai_should_punish(person_t p){
	return p.knows && !p.helps ? 1 : 0;
}

int should_punish_all(person_t *people, int people_count){
	int punished = 0;
	for(int i = 0; i < people_count && punished <= people_count / 2; ++i)
		if(ai_should_punish(people[i])) punished++;
	return punished > people_count / 2 ? 1 : 0;
}

int main(){
	person_t p1 = {1, 1};

	printf("Person knows = %d and helps = %d => should be punished = %d\n", 
p1.knows, p1.helps, ai_should_punish(p1));

	return 0;
}
