/* Problem : count the letters of the numbers from 1 to 1000 inclusive */
#include <stdio.h>
struct ONES {
    int table[11] = { 3 , 5 , 4 , 4 , 3 , 5 , 5 , 4 , 3 , 6 , 6 } ; // one through twelve
    int one=3;
    int two=3;
    int three=5;
    int four=4;
    int five=4;
    int six=3;
    int seven=5;
    int eight=5;
    int nine=4;
    int ten=3;
    int eleven=6;
    int twelve=6;
};

int main(void) {

    struct TENS {
        int table[3] = {4,4,3} ;
        int twen=4;
        int thir=4;
        int fif=3;
    };

    struct TENS_SUFF1 {int teen=4;};
    struct TENS_SUFF2 {int ty=2;} ;
    struct AND {int ands=3;} ;
    struct HUNDRED {int hundred=7;};
    struct THOUSAND {int thousand=8;} ;

    int sum = 0 ;

    struct ONES ones ;
    struct TENS tens ;
    struct TENS_SUFF1 t_suff1 ;
    struct TENS_SUFF2 t_suff2 ;
    struct HUNDRED hun ;
    struct AND ent ;
    struct THOUSAND thou ;
    for (int i = 0; i < 12; i++) {
        sum += ones.table[i] + i ; // Sum [1,12]
    }
    printf("%d\n",sum );
    sum += tens.table[1]+t_suff1.teen ; // sum 13
    for (int i = 3; i < 9; i++) {
        sum += ones.table[i]+t_suff1.teen ; // sum [13,19]
    }
    sum += tens.table[0]+t_suff2.ty ; // sum 20
    for (int i = 0; i < 9; i++) { // sum [21,29]
        sum += tens.table[0]+t_suff2.ty+ones.table[i] ;
    }
    sum += tens.thir+t_suff2.ty; // sum 30
    for (int i = 0; i < 9; i++) {
        sum += tens.thir+t_suff2.ty+ones.table[i] ; // sum [31,39]
    }
    for (int j = 3; j < 9; j++) {
        sum += ones.table[j]+t_suff2.ty ; // Sum 40,50,60,70,80,90
        for (int i = 0; i < 9; i++) {
            sum += ones.table[j]+t_suff2.ty+ones.table[i] ; // sum [41,49][51,59],[61,69],[71,79],[81,89],[91,99]
        }
    }
    for (int k = 0; k < 9; k++) {
        sum+=ones.table[k]+hun.hundred ; // sum 100,200,300,400,500,600,900
        for (int i = 0; i < 12; i++) {
            sum += ones.table[k]+hun.hundred+ent.ands+ones.table[i] ; // sum [101,112],[201,212] ...
        }
        sum += ones.table[k]+hun.hundred+ent.ands+tens.table[1]+t_suff1.teen ; // sum 113,213,313,413,...
        for (int i = 3; i < 9; i++) {
            sum += ones.table[k]+hun.hundred+ent.ands+ones.table[i]+t_suff1.teen ; // sum [114,119],[214,219],...
        }
        sum += ones.one+hun.hundred+ent.ands+tens.table[0]+t_suff2.ty ; // sum 120,220,320,...
        for (int i = 0; i < 9; i++) {
            sum += ones.table[k]+hun.hundred+ent.ands+tens.table[0]+t_suff2.ty+ones.table[i] ; // sum [121,129],[221,229],...
        }
        sum += ones.one+hun.hundred+ent.ands+tens.thir+t_suff2.ty; // sum 130,230,...
        for (int i = 0; i < 9; i++) {
            sum += ones.table[k]+hun.hundred+ent.ands+tens.thir+t_suff2.ty+ones.table[i] ; // sum [131,139],[231,239],...
        }
        for (int j = 3; j < 9; j++) {
            sum += ones.table[k]+hun.hundred+ent.ands+ones.table[j]+t_suff2.ty; // sum 140,150,..,240,250,...
            for (int i = 0; i < 9; i++) {
                sum += ones.table[k]+hun.hundred+ent.ands+ones.table[j]+t_suff2.ty+ones.table[i] ; // sum [141,149],[151,159],..,[241,249],[251,259],...
            }
        }

    }
    sum+= ones.one+thou.thousand;
    printf("Answer : %d\n",sum );
    return 0 ;
}
