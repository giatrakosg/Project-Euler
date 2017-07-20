#include <stdio.h>
void get_dec(int *dec_part,int divd,int size){
    int divisor = 10;
    for (int i = 0; i < size; i++) {
        if((divisor < divd)) {
            dec_part[i] = 0 ;
            divisor *= 10 ;
        }
        else {
            dec_part[i] = divisor / divd ;
            divisor %= divd ;
            divisor *= 10 ;
        }
    }

}
void print_arr(int *a,int length) {
    for (int i = 0; i < length; i++) {
        printf("%d",a[i] );
    }
    printf("\n");

}


int main(void) {
    int dec_part[400] ;
    get_dec(dec_part,7,400);
    print_arr(dec_part,400);


    return 0 ;
}
