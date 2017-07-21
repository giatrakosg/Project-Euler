#include <stdio.h>
#include <stdlib.h>
#define LENGTH 50000

/* problem : Find the d for which 1/d decimal part has
the longest reccuring cycle of digits */

/* Approach : Construct a table for each number with the divisors
for the classic long division ,then qsort it and count the number
of same digits ,then divide the buffer with that number */

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

void init(int *a,int length,int def) {
    for (int i = 0; i < length; i++) {
        a[i] = def ;
    }
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
    // seach for biggest chain of equal numbers
    int max = -1;
    for (int i = 0; i < LENGTH; i++) {
        int cyc = 1 ;
        while(a[i] == a[i + 1]) {
            cyc++;
            i++;
        }
        if(cyc > max){
            max = cyc ;
        }
    }
    return( LENGTH / max) ;

    return 0 ;
}

int main(void) {
    int dec_part[LENGTH] ;
    int k ;
    int max = -1 ;
    int tmp ;
    for (int i = 1; i < 1000; i++) {
        init(dec_part,LENGTH,-1);
        get_decimal(dec_part,i,LENGTH);
        if ((tmp = find_cycles(dec_part,LENGTH)) > max) {
            max = tmp ;
            k = i ;
        }
    }
    printf("Answe : %d\n",k );

    return 0 ;
}
