#include <stdio.h>
#include <stdlib.h>

int smaller(int);
int bigger(int);

int main(int argc, char **argv) {
    int num = atoi(argv[1]);
    printf("%d %d", bigger(num), smaller(num));
    return 0;
}

int bigger(int num) {
    int i = 0;
    while (((1 << ++i) < num) && (((1 << i) | num) == num));
    if((1 << i) > num) return num << 1;
    num ^= (3 << (i - 1));
    return num;
}

int smaller(int num) {
    int i = 0;
    while (((1 << i++) | num) == num);
    num ^= (3 << (i - 1));
    return num;
}
