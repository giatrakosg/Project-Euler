/* Problem : Calculate the sum of the diagonals of a spiral(1001x1001) */
/* Through examples we see that the sides of the created squares are */
/* of length 1 + 2*(N - 1) ,where N the level. */
/* We have that L(n) = 1 + 2n ,where n is the n'th sq.and L is the length of
its side */
/* S(n) = 4L(n) - 3 ,where S is number of elements of the n'th square */
/* F(n) = sum(i=0->i=n-1S(i) + 1 ,where F first element of n'th square*/
/* DR(n) = F(n) + (L(n) - 1)/2 ,element in Down Right corner of sq.n */
/* DL(n) = DR(n) + L(n) - 1 ,element in Down Left corner of sq.n */
/* UL(n) = DL(n) + L(n) - 1 ,element in Upper Left corner of sq.n */
/* UR(n) = UL(n) + L(n) - 1 ,element in Upper Right corner of sq.n */

#include <stdio.h>

int L(int n) {
    return (1+2*n) ;
}
int S(int n) {
    if(n == 0) return 1 ;
    return 8*n ; // 4*L(n) - 4
}
int F(int n) {
    if(n == 0) return 1 ;
    return F(n-1) + S(n-1);
}
int DR(int n) {
    return (F(n) + L(n) - 2) ; // the first element is 1 after the highest on the left side
}
int DL(int n) {
    return (DR(n) + L(n) - 1);
}
int UL(int n) {
    return (DL(n) + L(n) - 1);
}
int UR(int n) {
    return (UL(n) + L(n) - 1);
}
int main(void) {
    long sum = 1 ; // count 1 times the 1 of the 0th level
    for (int i = 1; i <= 500; i++) { // start after 1 in center
        sum += DR(i) + DL(i) + UL(i) + UR(i) ;
    }
    printf("Answer : %ld\n",sum );

    return 0 ;
}
