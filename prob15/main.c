/* Problem : Find number of paths going from top left to bottom right only moving right and down */
/* From combinatorics the formula is m + n choose m */
/* for m = n = 20 40 choose 20 */
/* 40! / 20! * 20! */
/* => 40*39*...*21 / 20 * 19 * .. */
/* => 2^10 * 39 * 37 * ... * 21 / 10! */
/* You can further simplify it to 2^3 39 * 37 * .. * 21 / 23850 */
/* but for sake of clarity I've left it as before */
#include <stdio.h>
unsigned long power(unsigned int base ,unsigned int expon){
    unsigned int i ;
    unsigned long prod = 1 ;
    for (i = 0; i < expon ; i++) {
        prod *= base ;
    }
    return prod ;

}
unsigned long factorial(unsigned int x){
    unsigned long prod = 1 ;
    unsigned long i ;
    for (i = 1; i <= x; i++) {
        prod *= i ;
    }
    return prod ;
}
int main(void){
    unsigned long prod = 1 ;
    unsigned long i ;
    for (i = 39; i >= 21; i-=2) {
        prod *= i ;
    }
    unsigned long z = power(2,10);
    unsigned long x = prod ;
    unsigned long y = factorial(10) ;
    unsigned long long result = (z * x) / y ;
    printf("Answer : %lld \n",result);
    return 0 ;
}
