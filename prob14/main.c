/* Problem : Find longest collatz chain of starting number < 1000000 */
/* Approace Eratosthenes shieve inspired method */
#include <stdio.h>
#include <stdlib.h>
#define BOUND 1000000
int is_even(long num){
    return !(num % 2);
}
int main(void){
    int i , j ;
    int count = 0 ;
    int count_max = -1 ;
    long max = -1 ;
    long num = 0 ;
    long sum = 0 ;
    int **numbers = (int **)malloc(1000 * sizeof(int *));
    for (i=0; i<1000; i++)
         numbers[i] = (int *)malloc(1000 * sizeof(int));
    for (i = 0; i < 1000; i++) {
        for ( j = 0; j < 1000; j++) {
            numbers[i][j] = sum ;
            sum++;
        }
    }
    for (i = 0; i < 1000; i++) {
        for (j = 0; j < 1000; j++) {
            num = numbers[i][j] ;
            count = 0 ;
            while(num != 1 && num > 0 ){
                if (is_even(num)) {
                    count++;
                    num /= 2 ;
                    if (num < BOUND) {
                        numbers[num / 1000][num % 1000] = 1; /* eliminate num ,since it is part of a larger circle so when we go compute it */
                                                            /* it won't be the best solution */
                    }
                }
                else{
                    count++;
                    num = 3*num + 1;
                    if (num < BOUND) {
                        numbers[num / 1000][num % 1000] = 1;
                    }
                }
            }
            if (count > count_max){
                count_max = count ;
                max = numbers[i][j] ;
            }
        }
    }
    printf("Answer ; %ld\n",max );


    return 0 ;
}
