/* Problem : Give names.txt sort alphabetically,then find its alphabetical value and multiply by position
   sum of all these values */
#include <stdio.h>
#include <stdlib.h>

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
void insert_sort(unsigned int **table,int size ,int start){
    if (start >= 0 ) {
        int i , j ;
        for (i = 0; i < size - 1; i++) {
            for (j = i + 1; j < size; j++) {
                if (table[j][start] <= table[i][start]) {
                    swap(table[j],table[i]);
                }
            }
        }
        insert_sort(table,size,start - 1);
    }
}
unsigned int calc_alph(unsigned int *a){
    unsigned int sum = 0 ;
    int i = 0 ;
    while(a[i]){
	       sum = sum + a[i] - 'A' + 1 ;
	       i++;
    }
    return sum ;
}
int islarger(char *str1,char *str2,int MAX_CHARS) {
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
    int COL = 20 ;
    int ROWS = 5500 ;
    int i ,j = 0 ;
    unsigned long long sum = 0 ;
    unsigned int **names = (unsigned int **)malloc(sizeof(unsigned int *) * ROWS);
    for (i = 0; i < ROWS; i++) {
        names[i] = (unsigned int *)malloc(sizeof(unsigned int) * COL);
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
            getc(fp); /*Get next "  */
            i++;
            j = 0 ;
    }
    fclose(fp);
    swap(names[i],names[i-1]);
    insert_sort(names,ROWS,COL);
    i = 0 ;
    while(!names[i][0]) {
        offset++;
        i++;
    }
    for (i = 0; i < ROWS ; i++) {
        sum += ((i + 1 - offset)*calc_alph(names[i]));
    }
    for (i = 0; i < ROWS; i++) {
        j = 0 ;
        printf("%d %u\n",i,calc_alph(names[i]));
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
    printf("COLIN = %u\n",calc_alph(names[937 + offset]) );
//    printf("Alphabetic Value of last name %d \n",calc_alp(names[name_count - 1]));
    return 0 ;
}
