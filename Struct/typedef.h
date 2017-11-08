#include<math.h>

typedef struct point_t{
	int x, y;
} point_t;

typedef struct line_t{
	point_t p[2]; 
} line_t;

typedef struct rect_t{
	int l,t,r,d;	
} rect_t;
