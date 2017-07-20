#include <stdio.h>
#include <stdlib.h>

void get_decimal(int *dec_part,int divd,int size){
    int divisor = 10;
    for (int i = 0; i < size; i++) {
        if(((divisor*10) < divd)) {
            dec_part[i] = divisor ;
            divisor *= 10 ;
        }
        else {
            dec_part[i] = divisor ;
            divisor %= divd ;
            divisor *= 10 ;
        }
    }

}
void print_array(int *a,int length) {
    for (int i = 0; i < length; i++) {
        printf("%d ",a[i] );
    }
    printf("\n");

}
// if the divisor is the same in two spots then there must be a cycle
// all nubmers have cycles
// Sort the array and check if there are doubles if there are then the cycle is of
// length #of_same / LENGTH
int cmpfun(const void *a,const void *b) {
    return (*(int *)a - *(int *)b);

}
int find_cycles(int *a,int length) {
    qsort(a,length,sizeof(int),cmpfun);
    print_array(a,length);
    // seach for biggest chain of equal numbers
    int max = -1 ;
    int cyc = 1 ;
    for (int i = 0; i < length - 1; i++) {

        if(a[i] == a[i + 1]){
            cyc++;
        }
        else {
            if(cyc > max){
                max  = cyc ;
            }
            cyc = 1 ;
        }
    }
    return (length / cyc)+1 ;

}

int main(void) {
    int divisor ;
    printf("Give divisor \n" );
    scanf("%d\n",&divisor );
    int dec_part[400] ;
    get_decimal(dec_part,divisor,400);
    print_array(dec_part,400);
    printf("%d\n",find_cycles(dec_part,400) );

    return 0 ;
}
