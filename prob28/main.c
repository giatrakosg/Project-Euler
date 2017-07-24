/* Problem : Calculate the sum of the diagonals of a spiral(1001x1001) */
/* Through examples we see that the sides of the created squares are */
/* of length 1 + 2*(N - 1) ,where N the level. */
/* We have that L(n) = 1 + 2n ,where n is the n'th sq.and L is the length of
its side */
/* S(n) = 4L(n) - 3 ,where S is number of elements of the n'th square */
/* F(n) = S(n) + S(n - 1) = 16n - 3 ,where F first element of sq. n */
/* DR(n) = F(n) + (L(n) - 1)/2 ,element in Down Right corner of sq.n */
/* DL(n) = DR(n) + L(n) - 1 ,element in Down Left corner of sq.n */
/* UL(n) = DL(n) + L(n) - 1 ,element in Upper Left corner of sq.n */
/* UR(n) = UL(n) + L(n) - 1 ,element in Upper Right corner of sq.n */



int main(void) {



    return 0 ;
}
