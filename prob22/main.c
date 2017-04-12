/* Problem : Give names.txt sort alphabetically,then find its alphabetical value and multiply by position
   sum of all these values */
#include <stdio.h>
#include <stdlib.h>
void sort(){}
void calc_alp(){}
int main(void){
    int c ;
    int COL = 20 ;
    int ROWS = 5500 ;
    int i ,j = 0 ;
    int **names = (int **)malloc(sizeof(int *) * ROWS);
    for (i = 0; i < ROWS; i++) {
        names[i] = (int *)malloc(sizeof(int) * COL);
    }
    FILE *fp = fopen("names.txt","r");
    i = 0 ;
    while(1){
            while((c = getc(fp)) != '"' ){
                names[i][j] = c ;
                j++;
            }
            if(getc(fp) == EOF){ /*Get comma or EOF */
                break ;
            }
            getc(fp); /*Get next "  */
            i++;
            j = 0 ;
    }
    fclose(fp);
    return 0 ;
}
