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
    if(num % 2 == 0){		/*Prime Decomposition  and calculating the aliquot sum*/
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
unsigned long triagle(unsigned long num){
    unsigned long i = 0 ;
    unsigned long sum = 0 ;
    for (i = 0; i <= num; i++) {
        sum += i;
    }
    return sum ;
}
int main(void){
    unsigned long num ;
    while(1){
        printf("Give number\n" );
        scanf("%lu \n",&num );
        printf("%d \n",divisor_number_v2(triagle(num)) );

    }

}
