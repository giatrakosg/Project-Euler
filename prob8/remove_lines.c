#include <stdio.h>
int main(void){
char ch ;
    while ((ch = getchar()) != EOF) {
        if (ch == '\n') {
            continue ;
        }
        else
            putchar(ch);
    }
}
