/*Problem :Find smallest number divisible ny all n[1,20] */
#include <stdio.h>
int main(void){

    long num ;
    long i , flag ;
    for ( num = 1; ; num++) {
        flag = 0 ;
        for ( i = 1; i <= 20; i++) {
            if (num % i != 0) {
                flag = 1;
                break ;
            }
        }
        if (!flag) {
            printf("%ld \n",num );
            break ;
        }
    }
    return 0 ;

}
