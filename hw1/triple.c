#include <stdio.h>

/*
 * This program takes two integers m,n, such that m > n.
 * It then produces a pythagorean triple where
 * s1 = m^2 - n^2
 * s2 = 2mn
 * hyp = m^2 + n^2.
 *  
 */
int main() {

    int m, n, s1, s2, hyp;
    printf("Please enter two integers with the first larger than the second > ");
    scanf("%d%d", &m, &n);

    s1 = m*m - n*n;
    s2 = 2*m*n;
    hyp = m*m + n*n;

    printf("The Pythagorean triple of %d and %d is %d, %d, and %d.\n", m,n,s1,s2,hyp);

    return 0;
}