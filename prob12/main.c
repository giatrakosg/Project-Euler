/* Problem : Find triangular number with ,500 divisors */

#include <stdio.h>
#include <math.h>
#define TERMS 500
int divisor_number(unsigned long num){
    unsigned long i ;
    int div_count = 0 ;
    for (i = 1; i <= num/2.0; i++) {
        if (num % i == 0 ) {
            div_count++;
            if (((double) num) / i >= (num / 2.0)) {
                div_count++;
            }
        }
    }
    return div_count;
}
int divisor_number_v2(unsigned long num ){
    int count = 2 ;
    unsigned long i ;
    if(num % 2 == 0){
        count+=2 ;
    }
    for(i = 3; i*i <= num ; i++){
        if(num % i == 0){
            count++ ;
            if ((num / i) > sqrt(num)) {
                count++;
            }
        }
    }
    return count ;
}
int main(void){
    unsigned long i ;
    unsigned long sum = 1;
    printf("%d \n",divisor_number_v2(28) );
    for (i = 2;; i++) {
        printf(".. " );
        sum += i ;
        if (divisor_number_v2(sum) == TERMS) {
            printf("Answer : %lu\n",i );
            return 0 ;
        }
    }
}
