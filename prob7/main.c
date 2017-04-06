/*Problem : Find 10.001 prime */
#define BOUND 10001
#include <stdio.h>
int check_if_prime(long num){
    long i ;
    if (num % 2 == 0) {
        return 0;
    }
    for (i = 3; (i*i) <= num; i+=2) {
        if (num % i == 0 ) {
            return 0 ;
        }
    }
    return 1 ;
}

int main(void){
    int place = 1 ;
    long i ;
    for (i = 3;; i+=2) {
        if (check_if_prime(i)) {
            place++;
            //printf("%d : %ld \n",place ,i );
            if (place == BOUND) {
                printf("Answer : %ld\n ",i);
                break ;
            }
        }
    }
    return 0 ;
}
