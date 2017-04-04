/* Problem : Find sum of all primes bellow 2 million */
#define PRIMES 2000000
#include <stdio.h>
int check_if_prime(unsigned long num){
    unsigned long i ;
    if (num % 2 == 0) {
        return 0;
    }
    for (i = 3; (i*i) <= num; i=i+2) {
        if (num % i == 0 ) {
            return 0 ;
        }
    }
    return 1 ;
}

int main(void){
    unsigned  long sum = 2 ;
    unsigned long i ;
    for (i = 3;i < PRIMES; i++) {
        if (check_if_prime(i)) {
            sum += i ;
        }
    }
    printf("Answer : %lu \n",sum);
    return 0 ;
}
