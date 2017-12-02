#include<stdio.h>
#include"typedef.h"
#include<math.h>

#define PI 3.14159265

float slope(line_t l){
        float y, x, val;
        val = 180.0 / PI;
        y = fabs(l.p[0].y - l.p[1].y);
       	x = fabs(l.p[0].x - l.p[1].x);
 	return atan(y / x) * val;
}


int main(){
	point_t p;
	line_t l[2];
	int x,y;
	for(int i = 1; i <= 2; ++i){	
		for(int j = 1; j <= 2; ++j){
			printf("\nX%d%d: ",i,j);
			scanf("%d", &x);	
			printf("\nY%d%d: ",i,j);
			scanf("%d", &y);
			p.x = x;
			p.y = y;
			l[i-1].p[j-1] = p;	
		}	
	}
	if(slope(l[0]) == slope(l[1])) printf("Prallel!");	
	else printf("Not prallel!");
	printf("\n");
	return 0;
}
