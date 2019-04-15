#include<stdio.h>
#include<stdio.h>
#include<stdbool.h>
#include<math.h>

#define N 10000

bool is_prime(int);
void n_primes(int);

int main(int argc, char const *argv[])
{
    n_primes(N);
    return 0;
}

bool is_prime(int num) 
{
    for(size_t i = 2; i <= sqrt(num); i++)
    {
        if (!(num % i))
            return false;
    }
    return true;
}

void n_primes(int n) 
{
    for(size_t i = 2; i < n; i++)
    {
        if (is_prime(i)) 
            printf("%ld\n", i);        
    }
    
}
