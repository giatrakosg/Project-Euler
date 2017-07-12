#include <stdio.h>

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
    int prod = 1 ;
    int i = 0 ;
    int n = 1;
    while((p % 2) == 0){
        i++;
        p /= 2 ;
    }
    for (int j = 1; j <= i; j++) {
        prod += power(2,i);
    }
    n *= prod ;
    i = 3 ;
    while((i*i) < p){
        int l = 0 ;
        prod = 1 ;
        while((p % i) == 0){
            l++;
            p /= i ;
        }
        for (int j = 1; j < l; j++) {
            prod += power(i,j);
        }
        n *= prod ;
        i+=2;
    }
    if(p > 2) n = n*(p + 1) - fterm ;
    else n = n - fterm ;
    return n ;

}

int main(void){
    printf("%d\n",sum_of_divs(28) );
    return 0 ;
}
