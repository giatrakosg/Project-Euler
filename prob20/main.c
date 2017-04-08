/* Problem : Find the digit sum of 100! */
/* My aproach is the same as in prob16 */
#include <stdio.h>
#include <stdlib.h>
int get_digit_sum(int x){
    int sum = 0 ;
    while(x % 10 != x){  /*Drop last digits and add them */
        sum += (x % 10) ;
        x %= 10 ;
    }
    sum += x ;
    return sum ;

}

int main(void){
    int *dec_number = (int *)malloc(sizeof(int) * 1000);
    int i ,s ,j ,tmp ;
    long sum = 0 ;
    dec_number[0] = 1 ;
    for (i = 1; i < 1000; i++) {
        dec_number[i] = 0 ;
    }
    for (i = 1; i < 101; i++) {
        s = 0 ;
        for (j = 0; j < 1000; j++) {
            tmp = (i * dec_number[j] + s) % 10 ;    /* Multiply by i ,add remainder from previous mod 10 */
            s = (i * dec_number[j] + s) / 10 ;      /* Get remainder */
            dec_number[j] = tmp ;                   /* Transfer */
        }
    }
    for (i = 0; i < 1000; i++) {
        sum += get_digit_sum(dec_number[i]) ; /* only needed for the MS digit */
    }
    printf("Answer : %ld\n",sum );


    return 0 ;
}
