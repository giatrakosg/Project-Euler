/*Problem find pythagorean triples such that a + b + c = 1000 */
#include <stdio.h>
#include <math.h>
int is_natural(double x){   /*Checks if x natural number */
    if ((floor(x) == x) && (x > 0)) {
        return 1 ;
    }
    return 0 ;
}
int main(void){
    double a , b , c ;
    for (b = 3;; b++) {/*Fix b as constant */
        c = ((double) ((2000*b) - (2*b*b) - 1000000.0))/(2*(b - 1000.0));   /*Solve for c */
        if(!is_natural(c)){ /*Check if natural */
            continue ;
        }
        a = sqrt(c*c - b*b);    /*Calculate a */
        if (!is_natural(a)) {   /*check if natural */
            continue;
        }
        printf("Answer : %.0f \n",a*b*c );
        break ;
    }
    return 0 ;

}
