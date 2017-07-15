/*Problem :Find smallest number divisible ny all n[1,20] */
/* Approach : we find the prime components of 1-20 and their highest powers */
/* multiply them all */


#include <stdio.h>

int prims[20] ;

void prim_comps(int a){
    int p = 0 ;

    while(!(a % 2)){
        p++;
        a /= 2 ;
    }
    if(prims[2 - 1] < p) prims[2 - 1] = p ;
    for (int i = 3; i*i < a; i+=2) {
        p = 0 ;
        while((a % i) == 0 ){
            p++;
        }
        if(prims[i - 1] < p) prims[i - 1] = p ;
    }

}

int main(void){
    for (int i = 0; i < 20; i++) {
        prims[i] = 0 ;
    }
    

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
