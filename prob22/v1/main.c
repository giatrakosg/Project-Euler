/* Problem : Give names.txt sort alphabetically,then find its alphabetical value and multiply by position
   sum of all these values */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main.h"

#define MAX_CHARS 40

void swap(unsigned int *a,unsigned int *b){
    unsigned int i = 0 ,temp ;
    while(a[i] || b[i] ){
        if(a[i] != b[i]){
            temp = a[i] ;
            a[i] = b[i] ;
            b[i] = temp ;
	    }
	    i++;
    }
}
void swap_str(char *str1,char *str2) {
    char *tmpstr = (char *)malloc(sizeof(char ) * MAX_CHARS);
    strcpy(tmpstr,str1);
    strcpy(str1,str2);
    strcpy(str2,tmpstr);
}
void insert_sort(char **table,int size ){
    int i , j ;
    for (i = 0; i < size; i++) {
        for (j = i; j < size; j++) {
            if(is_larger(table[i],table[j])){
                swap_str(table[i],table[j]);
            }
        }
    }
}
unsigned int calc_alph(char *str){
    unsigned int sum = 0 ;
    int i = 0 ;
    while(str[i]){
	       sum = sum + str[i] - 'A' + 1 ;
	       i++;
    }
    return sum ;
}
int is_larger(char *str1,char *str2) {
    int i = 0;
    while(str1[i] == str2[i] && i < MAX_CHARS - 2) {
        i++;
    }
    if (str1[i] > str2[i]) {
        return 1 ;
    }
    return 0 ;

}
int main(void){
    int c ,offset = 0 ;
    int COL = MAX_CHARS ;
    int ROWS = 5500 ;
    int i ,j = 0 ;
    unsigned long long sum = 0 ;
    char **names = (char **)malloc(sizeof(char *) * ROWS);
    for (i = 0; i < ROWS; i++) {
        names[i] = (char *)malloc(sizeof(char) * COL);
    }
    for (i = 0; i < ROWS; i++) {
        for ( j = 0; j < COL; j++) {
            names[i][j] = 0 ;
        }
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
            getc(fp); /* Get next   */
            i++;
            j = 0 ;
    }
    fclose(fp);
    insert_sort(names,ROWS);
    i = 0 ;
    while(!names[i][0]) {
        offset++;
        i++;
    }
    for (i = offset; i < ROWS ; i++) {
        sum = sum + ((i - offset + 1) * calc_alph(names[i]));
    }

    for (i = 0; i < ROWS; i++) {
        j = 0 ;
        printf("\n%d %u ",i,calc_alph(names[i]));
        while (names[i][j]) {
            printf("%c",names[i][j] );
            j++;
        }
        if (j) {
            printf("\n");
        }

    }
    printf("Offset : %d \n",offset );
    printf("Answer : %llu \n",sum  );
    printf("%s = %u Score = %u \n",names[937 + offset],calc_alph(names[937 + offset]),calc_alph(names[937 + offset]) * ((937 + offset) - offset + 1) );
    return 0 ;
}
