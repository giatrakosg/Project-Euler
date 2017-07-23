/* Problem : Find coefficients(a,b) for the formula */
/* n^2 + an + b ,so that it produces the maximus number of consecutive primes */

/* Aproach : So that it is prime for n = 0 it must be positive so */
/* b > 0, also it must me prime for n = 0 so b is prime .*/


#include <stdio.h>
#include <stdlib.h>

#define ESTM 250 // see https://en.wikipedia.org/wiki/Prime_number_theorem#Table_of_.CF.80.28x.29.2C_x_.2F_log_x.2C_and_li.28x.29
#define BND 1000
int check_if_prime(int num){
    int i ;
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
void print_array(int *a,int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ",a[i] );
    }
    printf("\n");

}

void init(int *a,int length,int def) {
    for (int i = 0; i < length; i++) {
        a[i] = def ;
    }
}

int main(void) {
    int b_primes_below1000[ESTM] ;
    init(b_primes_below1000,ESTM,0);
    int j = 0 ;
    for (int i = 2 ; i <= BND; i++) {
        if(check_if_prime(i)){
            b_primes_below1000[j] = i ;
            j++;
        }
    }
    print_array(b_primes_below1000,ESTM);
    return 0 ;
}
