/* Problem find path from top to bottom of triangle with largest sum */
/* Aproach : We start from bottom-up and add to the level above the max of its children */
#include <stdio.h>
#include <stdlib.h>
int max(int a,int b){
    if (a > b) {
        return a ;
    }
    return b ;

}
int main(void){
    long triang[100][100] ;
    int i , j ;
    FILE *fp = fopen("triangle.txt","r");
    for (i = 0; i < 100; i++) {
        for (j = 0; j <= i; j++) {
            fscanf(fp,"%ld",&triang[i][j]);
        }
    }
    fclose(fp);
    for (i = 98; i >= 0; i--) {
        for (j = 0; j <= i ; j++) {
            triang[i][j] += max(triang[i+1][j],triang[i+1][j+1]);
        }
    }
    printf("Answer : %ld\n",triang[0][0] );
    return 0 ;
}
