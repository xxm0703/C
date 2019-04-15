#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

#define CPU_COUNT 4
#define CYCLES_PER_INFO 5

typedef struct {
    unsigned int id, time;
} process_t;

typedef struct {
    process_t *processes;
    size_t process_count;
} cpu_t;

int calculate_time(cpu_t);
void run(cpu_t *);
int best_queue(cpu_t *);
void resize_queue(cpu_t *);
void display_info(cpu_t *);

int main(int argc, char const *argv[])
{
    cpu_t *machine = (cpu_t *)malloc(CPU_COUNT * sizeof(cpu_t));
    
    run(machine);

    return 0;
}

// Calculates time for the whole queue
int calculate_time(cpu_t cpu)
{
    int time = 0;

    for(size_t i = 0; i < cpu.process_count; i++)
        time += cpu.processes[i].time;

    return time;    
}

void run(cpu_t *machine)
{
    int indentifire = 1;
    char cmd[10]; 

    while(true)
    {
        for(size_t i = 0; i < CYCLES_PER_INFO; i++)
        {
            fgets(cmd, 10, stdin);
            
            if (!strcmp(cmd, "exit"))
                return;
            
            cpu_t *best_cpu = machine + best_queue(machine);
            resize_queue(best_cpu);

            process_t *tmp = best_cpu->processes + best_cpu->process_count - 1;
            *tmp = (process_t){indentifire++, atoi(cmd)};
        }

        display_info(machine);   
    }
    
}

// Returns index of shortest queue
int best_queue(cpu_t *machine)
{
    int best_cpu = 0;
    
    for(size_t i = 1; i < CPU_COUNT; i++)
        if (calculate_time(machine[best_cpu]) > calculate_time(machine[i]))
            best_cpu = i;
    return best_cpu;
}

// Resizes the process queue by 1
void resize_queue(cpu_t *cpu)
{
    if (cpu->process_count)
        cpu->processes = realloc(cpu->processes, ++cpu->process_count * sizeof(process_t));
    else
        cpu->processes = malloc(++cpu->process_count * sizeof(process_t));
}

// Displays info about every CPU
void display_info(cpu_t *machine)
{
    for(size_t i = 0; i < CPU_COUNT; i++)
        printf("Queue for processor %ld: %ld processes, Total time: %d\n", 
                    i, machine[i].process_count, calculate_time(machine[i]));
}