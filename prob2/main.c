/* Problem : Find sum of fibonaci ,even numbers < 4.000.000 */

#include <stdio.h>

int main(void){
    long f0 = 1, f1 = 2,temp ;
    long long sum = 2 ;
    while (f1 < 4000000) {
        temp = f1 ;
        f1 += f0 ;
        f0 = temp ;
        if (f1 % 2 == 0 ) {
            sum += f1 ;
        }
    }
    printf("Answer : %lld \n",sum );
    return 0 ;
}
