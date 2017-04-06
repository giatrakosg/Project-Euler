/*Problem : Find largest palindrome that is product of 2 3 digit numbers */

#include <stdio.h>
#include <stdlib.h>
int create_palindrome(int x1 ,int x2,int x3){
    return ((x3*100000) +( x2 * 10000) + (x1 * 1000) + (x1 *100) + (x2 * 10) + x3 );
}
int is_3_digit(int y ){
    if (y % 1000 == y) {
        return 1 ;
    }
    else return 0 ;
}
void find_3_dig_divisors(int y){
    int i ,flag = 0 ,k ;
    for (i = 100; i < 999; i++) {
        if (y % i == 0 ) {
            k = y / i ;
            flag = is_3_digit(k);
            if (flag) {
                printf("Answer : %d \n",y );
                exit(0);
            }
        }
    }
}

int main(void){
    int y ;
    int x1, x2 ,x3 ;
    for ( x3 = 9; x3 > 0; x3--) {
        for (x2 = 9; x2 >= 0; x2--) {
            for (x1 = 9; x1 >= 0; x1--) {
                y = create_palindrome(x1,x2,x3);
                find_3_dig_divisors(y);
            }
        }
    }
    return 0 ;
}
