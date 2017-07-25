/* Problem : count the letters of the numbers from 1 to 1000 inclusive */
#include <stdio.h>

int main(void) {
    enum ONES {one=3,two=3,three=5,four=4,five=4,six=3,seven=5,eight=5,nine=4,ten=3,eleven=6,twelve=6};
    enum TENS {twen=4,thir=4};
    enum TENS_SUFF {teen=4};
    enum TENS_SUFF2 {ty=2} ;
    enum AND {ands=3} ;
    enum HUNDRED {hundred=7};
    enum THOUSANDS {thousand=8} ;

    int sum = 0 ;

    enum ONES ones ;
    enum TENS tens ;
    ones = one ;
    tens = twen ;

    for (int i = 0; i < 12; i++) {
        sum += ones+i ; // Sum [1,12]
    }
    sum += tens+1+teen ; // sum 13
    for (int i = 3; i < 9; i++) {
        sum += ones+i+teen ; // sum [13,19]
    }
    sum += twen+ty ; // sum 20
    for (int i = 0; i < 9; i++) { // sum [21,29]
        sum += twen+ty+ones+i ;
    }
    sum += thir+ty; // sum 30
    for (int i = 0; i < 9; i++) {
        sum += thir+ty+ones+i ; // sum [31,39]
    }
    for (int j = 3; j < 9; j++) {
        sum += ones+j+ty ; // Sum 40,50,60,70,80,90
        for (int i = 0; i < 9; i++) {
            sum += ones+j+ty+ones+i ; // sum [41,49][51,59],[61,69],[71,79],[81,89],[91,99]
        }
    }
    for (int k = 0; k < 9; k++) {
        sum+=ones+k+hundred ; // sum 100,200,300,400,500,600,900
        for (int i = 0; i < 12; i++) {
            sum += ones+k+hundred+ands+ones+i ; // sum [101,112],[201,212] ...
        }
        sum += ones+hundred+ands+tens+1+teen ; // sum 113,213,313,413,...
        for (int i = 3; i < 9; i++) {
            sum += ones+k+hundred+ands+ones+i+teen ; // sum [114,119],[214,219],...
        }
        sum += ones+hundred+ands+twen+ty ; // sum 120,220,320,...
        for (int i = 0; i < 9; i++) {
            sum += ones+k+hundred+ands+twen+ty+ones+i ; // sum [121,129],[221,229],...
        }
        sum += ones+hundred+ands+thir+ty; // sum 130,230,...
        for (int i = 0; i < 9; i++) {
            sum += ones+k+hundred+ands+thir+ty+ones+i ; // sum [131,139],[231,239],...
        }
        for (int j = 3; j < 9; j++) {
            sum += ones+k+hundred+ands+ones+j+ty; // sum 140,150,..,240,250,...
            for (int i = 0; i < 9; i++) {
                sum += ones+k+hundred+ands+ones+j+ty+ones+i ; // sum [141,149],[151,159],..,[241,249],[251,259],...
            }
        }

    }
    sum+= one+thousand;
    printf("Answer : %d\n",sum );
    return 0 ;
}
