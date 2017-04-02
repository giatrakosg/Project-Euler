/* Problem : Find largest prime factor of  600851475143*/
#define PRIME 600851475143
#include <stdio.h>
#include <math.h>

int check_if_prime(long num){
    long i ;
    if (num % 2 == 0) {
        return 0;
    }
    for (i = 3; i*i < num; i+=2) {
        if (num % i == 0 ) {
            return 0 ;
        }
    }
    return 1 ;
}

int main(void){
    char flag = check_if_prime(PRIME) ;
    printf("%d %f\n",flag ,sqrt(PRIME));
    long check = ((long) ceil(sqrt(PRIME)));
    printf("%ld \n",check );
    for (; (check >= 3); check-=2) {
        //printf("%ld \n",check );
        if (PRIME % check == 0 ) {
            flag = check_if_prime(check);

        }
        if (flag) {
            break ;
        }
    }
    printf("check = %ld\n",check);

}
