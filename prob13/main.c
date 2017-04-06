/*Problem : Find first 10 digits of sum of given numbers in numbers.txt */
#include <stdio.h>
int count_digits(int num){
    int count = 0 ;
    while((num / 10)){ /*While there is still a digit left */
        count++;
        num /= 10 ;     /* Drop last digit */
    }
    count++;    /*Count last */
    return count;
}
int main(void){
    int numbers[100][50];
    int sumn[50];
    int sum = 0 ;
    int i , j ;
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 50; j++) {
            numbers[i][j] = getchar() - '0';
        }
        getchar();
    }
    for (i = 0; i < 100; i++) {
        for (j = 0; j < 50; j++) {
            printf("%d", numbers[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
    for (i =  49; i >= 0; i--) {
        sum = 0 ;
        for (j = 0; j < 100; j++) {
            sum += numbers[j][i];
        }
        sumn[i] = sum ;
    }
    for (i = 0; i < 50; i++) {
        printf("%d ",sumn[i] );
    }
    for (i = 49; i >= 1; i--) {
        sumn[i - 1] += (sumn[i] / 10) ;
        sumn[i] %= 10 ;
    }
    printf("\n ------ \n");
    for (i = 0; i < 50; i++) {
        printf("%d ",sumn[i] );
    }
    putchar('\n');
    printf("Answer :" );
    for (size_t i = 0; i < 10 - count_digits(sumn[0]) + 1; i++) { /*All extra digits are concentrated to the start */
        printf("%d",sumn[i] );
    }
    printf("\n");
    return 0 ;
}
