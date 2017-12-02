#include<stdio.h>

typedef struct monitor_t{
	char name[20];
	float diagonal;
	int mark;
} monitor_t;

monitor_t read_monitor(){
	monitor_t mon;
	printf("Name:");
	fgets(mon.name, 20, stdin);
	printf("Diag:");
	scanf("%f", &mon.diagonal);
	printf("Mark:");
	scanf("%d", &mon.mark);
	return mon;
}

monitor_t choose_monitor(monitor_t monitors[5], float diagonal){
	monitor_t best = monitors[0];
	for(int i = 1; i < 5; ++i)
		if (monitors[i].diagonal == diagonal){
			if (best.diagonal != diagonal) best = monitors[i];
			else if (monitors[i].mark > best.mark) best = monitors[i];
		}
	return best;
}

int main(){
	monitor_t monitors[5];
	for(int i = 0; i < 5; ++i){
		monitors[i] = read_monitor();
		printf("%c", getchar());	//Because there is left one '\n' from fgets 
	}
	printf("%s", choose_monitor(monitors, 27.5).name);	
}
