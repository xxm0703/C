#include"typedef.h"
#include<stdio.h>

int contains(rect_t rec, rect_t other);
rect_t union_rect(rect_t rec, int left, int top);

int main(){
	rect_t rec, rec1;

	printf("First Rectangle:\n");	

	printf("Left: ");
	scanf("%d", &rec.l);

	printf("Up: ");
	scanf("%d", &rec.t);

	printf("Down: ");
	scanf("%d", &rec.d);

	printf("Right: ");
	scanf("%d", &rec.r);

	printf("Second Rectangle:\n");	

	printf("Left: ");
	scanf("%d", &rec1.l);

	printf("Up: ");
	scanf("%d", &rec1.t);

	printf("Down: ");
	scanf("%d", &rec1.d);

	printf("Right: ");
	scanf("%d", &rec1.r);

	printf("%d\n", contains(rec,rec1));
	
	rect_t moved = union_rect(rec, 4, -7);

	printf("Original: %d %d %d %d\n", rec.t,rec.l,rec.d,rec.r);
	printf("Moved: %d %d %d %d\n", moved.t,moved.l,moved.d,moved.r);

	return 0;
}

int contains(rect_t rec, rect_t other){
	if (rec.r >= other.r &&
	rec.t >= other.t &&
	rec.d <= other.d &&
	rec.l <= other.l) return 1;
	return 0;
}

rect_t union_rect(rect_t rec, int left, int top){
	rec.t += top;
	rec.d += top;
	rec.r += left;
	rec.l += left;	
	return rec;
}

