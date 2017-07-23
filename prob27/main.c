/* Problem : Find coefficients(a,b) for the formula */
/* n^2 + an + b ,so that it produces the maximus number of consecutive primes */

/* Aproach : So that it is prime for n = 0 it must be positive so */
/* b > 0, also it must me prime for n = 0 so b is prime .The search space for*/
/* b is reduced to approx.200 */

/* For n = 1 the formula is a + b + 1 and it must be positive so */
/* a+b+1>0=>a+1>-b=>a>-b-1  thus a = -b is the first integer to start seach from */


#include <stdio.h>
#include <stdlib.h>

#define ESTM 250 // see https://en.wikipedia.org/wiki/Prime_number_theorem#Table_of_.CF.80.28x.29.2C_x_.2F_log_x.2C_and_li.28x.29
#define BND 1000
int check_if_prime(int num){
    if(num <= 0) { return 0 ; }
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

int get_chain(int co_a,int co_b) {
    /* returns the number of consecutive primes */
    int n = 0 ;
    int count = 0 ;
    while (check_if_prime(n*n + co_a*n + co_b)) {
        count++;
        n++;
    }
    return count ;
}

int main(void) {
    int primes_less1000[ESTM] ;
    init(primes_less1000,ESTM,0);
    int j = 0 ;
    for (int i = 2 ; i <= BND; i++) {
        if(check_if_prime(i)){
            primes_less1000[j] = i ;
            j++;
        }
    }
    
    j = 0 ;
    int a , b ;
    int max = -1 ;
    int maxa = -1000 ;
    int maxb = -1000 ;
    for (j = 0; primes_less1000[j] != 0; j++) {
        b = primes_less1000[j] ;
        for (a = -b; a < 1000; a++) {
            int c = get_chain(a,b);
            if(c > max){
                maxa = a ;
                maxb = b ;
                max = c ;
            }
        }
    }
    printf("Answer = %d \n",maxb*maxa);
    return 0 ;
}
