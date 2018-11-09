#include <stdio.h>

int xor(int, int);

int main(){
    int a = 12;
    int b = 6;
    printf("%d", xor(a,b));
    return 0;
}

int xor(int a, int b){
    return ~(a&b)&(a|b);
}