/* Problem : Find 13 adjacent digits of 1000-digit number with biggest product */
#include <stdio.h>
#define LENGTH 13
long calc_prod(int *x,int start){
    long prod = 1;
    int i ;
    for (i = start; i < start + LENGTH; i++) {
        prod *= x[i];
    }
    return prod;
}

int main(void){
    char ch ;
    int i , j , k ;
    int number[1000];
    int count_nl = 0 ;
    long max ,tmp ;
    FILE * fp = fopen("number_no_lines.txt","r");
    for (i = 0; i < 1000; i++) {
        number[i] = fgetc(fp) - '0';
    }
    fclose(fp);
    max = -1 ;
    for (size_t i = 0; i < 1000 - LENGTH; i++) {
        tmp = calc_prod(number,i);
        if (tmp > max) {
            max = tmp ;
        }
    }
    printf("Answer : %ld \n",max );
    return 0 ;

}
