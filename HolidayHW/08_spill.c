#include <stdio.h>

int w, h;

void spill(char (*surf)[w], short, short, char, short);

int main(){
	scanf("%d %d", &w, &h);
	char surface[h][w];
	for(int i = 0; i < h; ++i)
		scanf("%s", surface[i]);	
	for(int i = 0; i < h; ++i)
		for(int j = 0; j < w; ++j)
			spill(surface, j, i, surface[i][j], 1);	
	for(int i = 0; i < h; ++i){
		for(int j = 0; j < w; ++j)
			printf("%c",surface[i][j]);	
		printf("\n");
	}
	return 0;
}

void spill(char (*surf)[w], short x, short y, char type, short first_call){
	if(h == y || w == x || x < 0 || y < 0) return;
	if(type == '.' || surf[y][x] == '#' || (surf[y][x] == type && !first_call)) return;
	if((surf[y][x] == 'O' || surf[y][x] == '*') && surf[y][x] != type) surf[y][x] = '@';
	else if(surf[y][x] == '.') surf[y][x] = type;
	spill(surf, x, y+1, type, 0);
	spill(surf, x+1, y, type, 0);
	spill(surf, x-1, y, type, 0);
	spill(surf, x, y-1, type, 0);
}

