/* Problem : count letter of first 1000 numbers */

#include <stdio.h>
struct ones {
    int table[9] ;

};
struct tens {
    int table[8]; // twen,thir,for,fif,six,seven,eight,nine
    int ten ;
    int eleven ;
    int twelve ;
    int thir ;
    int _for ;
    int fif ;
    int six ;
    int seven ;
    int eight  ;
    int nine ;
    int four ;

};
struct hundreds {
    int table[9]  ;//one,two,three,four,five,six,seven,eight ,nine ,ten
};
struct suffix {
    int teen ;
    int ty  ;
    int _and  ;
    int hundred  ;
};
void init_ones(struct ones *a) {
    a->table[0] = 3 ;
    a->table[1] = 3 ;
    a->table[2] = 5 ;
    a->table[3] = 4 ;
    a->table[4] = 4 ;
    a->table[5] = 3 ;
    a->table[6] = 5 ;
    a->table[7] = 5 ;
    a->table[8] = 4 ;
}
void init_tens(struct tens *a) {
    a->table[0] = 4 ;
    a->table[1] = 4 ;
    a->table[2] = 3 ;
    a->table[3] = 3 ;
    a->table[4] = 3 ;
    a->table[5] = 5 ;
    a->table[6] = 5 ;
    a->table[7] = 4 ;

    a->ten = 3 ;
    a->thir = 4 ;
    a->_for = 4 ;
    a->fif = 3 ;
    a->six = 3 ;
    a->seven = 5 ;
    a->eight = 5 ;
    a->nine = 4 ;
    a->eleven = 5 ;
    a->four = 4 ;
}
void init_suff(struct suffix *a) {
    a->teen = 4 ;
    a->ty = 2 ;
    a->_and = 3 ;
    a->hundred = 7 ;
}
int main(void) {
    // if you count everything from 1 to 99 then you just multiply by 9
    int sum_1to999 =  0;
    int sum_1t99 = 0 ;
    int sum_1t9 = 0 ;
    struct ones ONES ;
    struct tens TENS ;
    struct suffix SUFF ;

    init_ones(&ONES);
    init_tens(&TENS);
    init_suff(&SUFF);
    for (int i = 0; i < 9; i++) {
        sum_1t9 += ONES.table[i] ;
    }
    int sum_10t19 = 0 ;
    sum_10t19 += TENS.ten + TENS.eleven + TENS.twelve + TENS.thir + SUFF.teen + TENS.four + TENS.fif + TENS.six + TENS.seven + TENS.eight + TENS.nine + 6*SUFF.teen ;
    int sum_20t99 = 0 ;
    for (int i = 0; i < 8; i++) {
        sum_20t99 += 9*(TENS.table[i] + SUFF.ty) + sum_1t9 ;
    }
    sum_1t99 = sum_1t9 + sum_10t19 + sum_20t99 ;
    for (int i = 0; i < 9; i++) {
        sum_1to999 += 99*(ONES.table[i] + SUFF.hundred + SUFF._and) + sum_1t99 ;
        sum_1to999 += ONES.table[i] + SUFF.hundred ;
    }
    sum_1to999 += 3 + 8 ; // +one thousand
    printf("Answer : %d\n",sum_1to999 );
    return 0;
}
