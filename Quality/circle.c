#include<stdio.h>
#include<math.h>

#define PI 3.14

typedef struct point{
	float x,y;
} point_t;

typedef struct circle{
	point_t center;
	float rad;	
} circle_t;

float perimeter(circle_t cir){
	return cir.rad*2*PI;
}

float surface(circle_t cir){
	return PI*cir.rad*cir.rad;
}

int qad(point_t pt){
	int i;
	if(pt.x > 0){
		if(pt.y > 0) i = 1;
		else i = 4;
	}else{
		if(pt.y > 0) i = 3;
		else i = 2;
	}
	return i;
}

void decart(circle_t cir){
	int quadrants[] = {0, 0, 0, 0};  //Qadrants where is the circle
	int i = qad(cir.center)-1; 
	quadrants[i] = 1;
	if(sqrt(pow(fabs(cir.center.x),2)+pow(fabs(cir.center.y), 2)) < cir.rad) quadrants[(i+2)%4] = 1;	//abs(x)/x 
	int a = (fabs(cir.center.x)/cir.center.x)*(fabs(cir.center.y)/cir.center.y);
	if(fabs(cir.center.y) < cir.rad) quadrants[(i - a) % 4 == -1 ? 3 : (i - a) % 4] = 1;
	if(fabs(cir.center.x) < cir.rad) quadrants[i + a] = 1;
	for(int j = 0; j < 4; ++j){
		if(quadrants[j]) printf("The circle is in %d quadrant...\n", j+1);
	}
}

int main(){
	point_t center = {2,-2};
	circle_t circle = {center, 3};
	decart(circle);
	return 0;
}









