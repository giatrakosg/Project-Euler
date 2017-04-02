/*Problem : Find sum of all multiples of 3 OR 5 ,bellow 1000 */
#include <stdio.h>

int main(void){
    int num ;
    long sum = 0 ;
    for (num = 0; num < 1000; num++) {
        if (num % 3 == 0 || num % 5 == 0) {
            sum += num ;
        }
    }
    printf("Answer :%ld \n",sum );
    return 0 ;
}
