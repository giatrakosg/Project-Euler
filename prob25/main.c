#include <stdio.h>

/* Problem : find the first 1000digit fibbonaci number */
/* Approch : Have to work with arrays to represent nubmers */
#define DIGITS 1001

void init(int *k) {
    for (int i = 0; i < DIGITS; i++) {
        k[i] = 0 ;
    }
}

void add(int *a,int *b) {
    for (int i = DIGITS - 1; i >= 1; i--) {
        a[i] = (a[i] + b[i]) % 10 ;
        b[i-1] += ((a[i] + b[i]) / 10) ;
    }
}
void assign(int *dst,int *src) {
    for (int i = 0; i < DIGITS; i++) {
        dst[i] = src[i] ;
    }
}
void print(const int *a) {
    for (int i = 0; i < DIGITS; i++) {
        printf("%d ",a[i] );
    }
    printf("\n");
}

int main(void) {
    int number[DIGITS];
    int prev[DIGITS];
    int tmp1[DIGITS];
    int tmp2[DIGITS];
    init(number);
    init(prev);
    init(tmp1);
    init(tmp2);
    number[DIGITS - 1] = 1 ;
    int count = 1 ;
    while(number[1] == 0){
        assign(tmp1,number);
        assign(tmp2,prev);
        add(number,tmp2);
        assign(prev,tmp1);
        count++;
    }
    print(number);
    printf("Answer : %d\n",count );

    return 0 ;
}
