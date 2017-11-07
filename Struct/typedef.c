#include<stdio.h>
typedef struct point_t{
	int x;
	int y;
} point;
int main(){
	point a;
	a.x = 3;
	a.y = 4;
	printf("%d %d\n", a.x, a.y);
}
