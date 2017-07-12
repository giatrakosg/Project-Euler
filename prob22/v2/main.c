#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ROWS 5500
#define COL 40
int str_cmp(const void *a,const void *b){
    const char *pa = *(const char **)a;
    const char *pb = *(const char **)b;
    return strcmp(pa,pb);

}
int calc_alph(char *str){
    int sum = 0 ;
    int i = 0 ;
    while(str[i]){
	       sum = sum + str[i] - 'A' + 1 ;
	       i++;
    }
    return sum ;
}
int main(void){
    int i , j ;
    char c ;
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

    int offset = 0 ;
    for(i = 0;i < ROWS ;i++)
        printf("%s\n",names[i] );
    int len = sizeof(names) / sizeof(char *) ;
    qsort(names,ROWS,sizeof(char *),str_cmp);
    for(i = 0;i < ROWS ;i++){
        printf("%s\n",names[i] );
        if(strlen(names[i]) == 0) offset++;
    }
    long long sum ;
    for(i = 0;i < ROWS ;i++){
        sum += (calc_alph(names[i]) * (i - offset + 1));
    }
    printf("%s alph=%d ",names[937+offset],calc_alph(names[937+offset]) );
    printf("%lld offset = %d\n",sum,offset );

}
