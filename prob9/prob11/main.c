/*Problem find largest product of 4 diag,up,down numbers on grid(see grid.txt) */

#include <stdio.h>
int grid[26][26];
int calc_diag_right(int i ,int j ){ /*Diagonal to the right */
        return (grid[i][j]*grid[i+1][j+1]*grid[i+2][j+2]*grid[i+3][j+3]);
}
int calc_right(int i,int j){
    return (grid[i][j+1]*grid[i][j+2]*grid[i][j+3]*grid[i][j]);
}
int calc_down(int i ,int j){
    return (grid[i][j]*grid[i+1][j]*grid[i+2][j]*grid[i+3][j]);
}
int calc_diag_left(int i ,int j){   /*Diagonal to the left */
    return (grid[i][j]*grid[i+1][j-1]*grid[i+2][j-2]*grid[i+3][j-3]);
}
int max_4(int a ,int b ,int c ,int d){
    int nr[4] = { a ,b ,c ,d};
    int i ;
    int max = -1 ;
    for (i = 0; i < 4; i++) {
        if (nr[i] > max) {
            max = nr[i] ;
        }
    }
    return max ;
}
int main(void){
    int i , j ,max =  - 1;
    for (i = 0; i < 26; i++) {
        for (j = 0; j < 26; j++) {
            grid[i][j] = 0;
        }
    }
    FILE *fp = fopen("grid.txt","r");
    for (i = 3; i < 23; i++) {
        for (j = 3; j < 23; j++) {
            fscanf(fp,"%d \n",&grid[i][j] );
        }
    }
    fclose(fp);
    for (i = 3; i < 23; i++) {
        for (j = 3; j < 23; j++) {
            printf("%02d ",grid[i][j] );
        }
        printf("\n");
    }

    for (i = 3; i < 23; i++) {
        for (j = 3; j < 23; j++) {
            if (max_4(calc_down(i,j),calc_diag_right(i,j),calc_right(i,j),calc_diag_left(i,j)) > max) {
                max = max_4(calc_down(i,j),calc_diag_right(i,j),calc_right(i,j),calc_diag_left(i,j));
            }
        }
    }
    printf("Answer : %d \n",max );
    return 0 ;
}
