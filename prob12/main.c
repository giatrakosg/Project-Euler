/* Problem : Find triangular number with ,500 divisors */
/* N = p1^(n1)*p2(n2)... ,where px = prime implicant x ,n power */
/* d(n) = (n1 + 1)*(n2 + 1)* ... */
#include <stdio.h>
#include <math.h>
#define TERMS 500
int count_divisors(unsigned long num){
    unsigned long i ;
    int count = 0 ;
    int prod = 1 ;
    while(num % 2 == 0) {
        count++;
        num /= 2 ;
    }
    prod *= (count + 1);
    for (i = 3; (i*i) <= num; i+=2) {
        count = 0 ;
        while(num % i == 0 ) {
            count++;
            num /= i ;
        }
        prod *= (count + 1) ;
    }
    if (num != 1) {
        prod *= 2 ;
    }
    return prod ;
}
int main(void){
    unsigned long i ;
    unsigned long sum = 1 ;
    for (i = 2;; i++) {
        sum += i ;
        if (count_divisors(sum) > TERMS) {
            printf("Answer : %lu \n",sum );
            break ;
        }
    }
    return 0 ;
}
