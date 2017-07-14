#include <stdio.h>
#include <stdlib.h>

/* Problem : find the millionth permutaion  */
/* of the digits 0 to 9                     */

/* Approach algorithm L check picture */
void print_digs(int *A){

    for (int i = 0; i < 10; i++) {
        printf("%d",A[i] );
    }
    printf("\n");
}
void swap(int *a,int *b) {
    int tmp = *a ;
    *a = *b ;
    *b = tmp ;

}
int main(void) {

    int dig[] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 };
    int n = 9 ;
    int j = n ;
    int l ;
    int count = 0 ;
    while(j != -1) {
        count++;
        if(count == 1000000){
            printf("Answer : ");
            print_digs(dig);
            break ;
        }
        j = n - 1 ;
        while(dig[j] >= dig[j+1])
            j--;
        l = n ;
        while(dig[j] >= dig[l])
            l--;
        swap(&dig[l],&dig[j]);
        int k = j + 1;
        l = n ;
        while(k < l) {
            swap(&dig[k],&dig[l]);
            k++;
            l--;
        }

    }


    return 0 ;
}
