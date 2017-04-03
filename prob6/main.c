/* Problem : Find (1^2 + 2^2 + .. + 100^2) - (1 + 2 + .. +100)^2 */
/* Using telescoping sums we get x = (1^2 + 2^2 + .. + 100^2) , y = (1 + 2 + .. +100)^2 */
/* x + y = ((n+1)^3 - 1) / 3 */
/* x - y = x + y - 2y */
/* y =  (n + 2) / 2 */
/* Went for the stupid solution */
#include <math.h>
#include <stdio.h>
#define N 100
double sum_1_power(int n){
    int i = 1 ;
    int sum = 0 ;
    for (; i <= N; i++) {
        sum += i ;
    }
    return sum ;
}

double sum_2_power(int n){
    int i = 1 ;
    long sum = 0 ;
    for ( i = 1; i <= N; i++) {
        sum +=pow(i,2);
    }
    return sum ;
}
int main(void){
    printf("%f\n",pow(sum_1_power(N),2) - sum_2_power(N) );

}
