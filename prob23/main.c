/*******************************************************/
/*  Approach sieve find all the can be written and add them                                                      */
/*                                                      */
/*******************************************************/


#include <stdio.h>
#include <stdlib.h>
#define LIM 28123

int power(int base,int exp){
    int prod = 1 ;
    for (int i = 0; i < exp; i++) {
        prod *= base ;
    }
    return prod ;

}
int sum_of_divs(int p){
    int fterm = p ;
    int prod = 0 ;
    int i = 0 ;
    int n = 1;
    while((p % 2) == 0){
        i++;
        p = p / 2 ;
    }
    for (int j = 0; j <= i; j++) {
        prod += power(2,j);
    }
    n *= prod ;
    i = 3 ;
    while((i*i) <= p){
        int l = 0 ;
        prod = 0 ;
        while((p % i) == 0){
            l++;
            p /= i ;
        }
        for (int j = 0; j <= l; j++) {
            prod += power(i,j);
        }
        n *= prod ;
        i+=2;
    }
    if(p > 2){
        n = (n*(p + 1)) - fterm ;
    }
    else {
        n = n - fterm ;
    }
    return n ;

}

int is_abundant(int n){
    if ((sum_of_divs(n) > n)) {
        return 1 ;
    }
    return 0 ;
}
int cmp_fun(const void *a,const void *b) {
    return (*(int *)b - *(int *)a);
}

int main(void){
    int k = 1 ;
    int abunds[7000] ;
    int abundcount = 0 ;

    for (int i = 0; k < LIM; k++) {
        if(is_abundant(k)){
            abundcount++;
            abunds[i] = k ;
            i++;
        }
    }
    long long sum = 0 ;
    for (int i = 0; i < LIM; i++) { /* iterates through all numbers */
        int flag = 1 ;
        for (int j = 0; j < abundcount; j++) { /* iterates through all abundant numbers */
            int key = i-abunds[j];
            if(((int *) bsearch(&(key),abunds,abundcount,sizeof(int),cmp_fun)) != NULL){
                flag = 0 ;
                break ;
            }
        }
        if(flag){
            sum += i ;
        }
    }
    printf("%lld\n",sum);
    printf("%d\n",abundcount );

    return 0 ;
}
/* the approach is to create a table with all abundant numbers
/* then go through all numbers up to the limit and and iterate through
/* the abundant number then binary search if the difference is on
/* the table
*/
