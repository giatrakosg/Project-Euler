/* Problem : Find amicable numbers under 1000 */
/* Aliquot Sum = (1 + p1 + p1 ^ 1 + .. +p1^n)(1 + p2 + p2^2 + ... + p2^n).... where p_i , prime implicant , n power */
#define BOUND 10000
#include <stdio.h>
int power(int base,int expn){
    int res = 1 ;
    int i ;
    for (i = 0; i < expn; i++) {
        res *= base ;
    }
    return res ;
}
int get_divisor_sum(int num){
    int first_term = num ;
    int i , j ;
    int prod = 1 ;
    int p_count = 0 ;
    int sum = 0 ;
    while(num % 2 == 0){
        p_count++;
        num /= 2 ;
    }
    for(i=0;i <= p_count;i++)
	sum += power(2,i);
    prod *= sum;
    for (i = 3; i*i <= num; i+=2) {
        p_count = 0 ;
        sum = 0 ;
        while (num % i == 0) {
            p_count++;
            num /= i ;
        }
	for(j=0;j<=p_count;j++)
	   sum += power(i,j);
      prod *= sum  ;
    }
    if (num > 1) {
	prod = prod*(num + 1) - first_term;
    }
    else
	prod -= first_term ;
    return prod ;
}
int main(void) {
    int sum = 0 ;
    int i ;
    for (i = 2; i < BOUND; i++) {
        if (get_divisor_sum(get_divisor_sum(i)) != get_divisor_sum(i)) { /* not  2 or 6 where d(2) = 2 */
	   if(get_divisor_sum(get_divisor_sum(i)) == i)
            	sum += i ;
        }
    }
    printf("Answer : %d \n",sum  );
    return 0;
}
