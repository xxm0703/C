#include"typedef.h"
#include<stdio.h>
//3 = a  
//9-4a

int main(){
	point_t p1, p2;
	p2.x = 2;
	p2.y = 3;
	p1.x = 4;
	p1.y = 9;
	float a = 1,b;
	for(int i=0;i<100;++i){
		b = p1.y-p1.x*a;
		a = (p2.y-b)/p2.x;
	}
	printf("f(x) = %f*x + %f", a, b);

	return 0;
}
