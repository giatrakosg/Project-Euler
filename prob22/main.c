/* Problem : Give names.txt sort alphabetically,then find its alphabetical value and multiply by position
   sum of all these values */
#include <stdio.h>
#include <stdlib.h>

void swap(int *a,int *b){
    int i = 0 ;
    while(a[i] || b[i] ){
	if(a[i] != b[i]){ /*Xor Swaping only works when a , b different */
		a[i] = a[i] ^ b[i] ;
		b[i] = b[i] ^ a[i] ;
		a[i] = a[i] ^ b[i] ;
	}
	i++;
    }

}
void insert_sort(int **table,int size,int length){
    int i , j , k , max ;
    for(i = 0;i < length;i++){
	for(j = 0;j < size;j++){
	    max = table[i][j];
		for(k = 0 ;k < size;k++){
		    if(table[i][k] > max){
			max = table[i][k];
			swap(table[k],table[j]);
		    }
		}
	}
    }



}
int calc_alp(int *a){
    int sum = 0 ;
    int i = 0 ;
    while(a[i]){
	sum += a[i] - 'A' + 1 ;
	i++;
    }
    return sum ;
}
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
    int name_count = 0 ;
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
    swap(names[i],names[i-1]);
    name_count = i + 1;
    insert_sort(names,ROWS,COL);
    for (i = 0; i < name_count ; i++) {
        j = 0 ;
        while(names[i][j] != 0 ){
            printf("%c",names[i][j] );
            j++;
        }
        printf("\n");
    }
    fclose(fp);
    printf("Alphabetic Value of last name %d \n",calc_alp(names[name_count - 1]));
    return 0 ;
}
