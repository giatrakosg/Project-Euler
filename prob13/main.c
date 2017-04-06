#include <stdio.h>

int main(void){
    int numbers[100][50];
    int sum[120];
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
}
