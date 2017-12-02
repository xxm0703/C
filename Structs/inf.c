#include"typedef.h"
#include<stdio.h>

int main(){
	point_t p1, p2;
	p2.x = 2;
	p2.y = 3;
	p1.x = 4;
	p1.y = 9;
	float a, b;
	a = (p2.y - p1.y) / (p2.x - p1.x);
	b = p1.y-a*p1.x;
	printf("f(x) = %.2f*x + %.2f", a, b);

	return 0;
}
