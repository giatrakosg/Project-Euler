/*Problem :Find smallest number divisible ny all n[1,20] */
/* Approach : we find the prime components of 1-20 and their highest powers */
/* multiply them all */


#include <stdio.h>
void prim_comps(int a){
    int p = 0 ;
    int i = 2 ;
    while(!(a % 2)){
        p++;
        a /= 2 ;
    }
    
    for (int i = 3; i < count; i++) {
        /* code */
    }

}

int main(void){



    return 0 ;

}
/*
1
2
3
4 2*2
5
6 2*3
7
8 2*2*2
9 3*3
10 2*5
11
12 2*2*3
13
14 2*7
15 3*5
16 2*2*2*2
17
18 2*3*3
19
20 2*2*5

1*2^4*3^2*5*7*11*13*17*19
= 1*16*9*5*7*11*13*17*19

*/
