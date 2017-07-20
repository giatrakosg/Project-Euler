#include <stdio.h>
void get_dec(int *dec_part,int divd,int size){
    int divisor = 10;
    for (int i = 0; i < size; i++) {
        dec_part[i] = divisor / divd ;
        if((divisor / divd) == 0) {
            divisor *= 10 ;
        }
        else
            divisor -= divd ;
    }

}

int main(void) {
    int dec_part[400] ;



    return 0 ;
}
