/*
 * 分解质因数，例如90=2*3*3%
 */

#include <stdio.h>
void main(){
    int n, i;
    scanf("%d", &n);
//    printf("%d=", n);
//    for (i = 2; i <= n; ++i) {
//        while (n >= i) {
//            if (n % i == 0) {
//                printf("%d*", i);
//                n = n / i;
//            } else
//                break;
//        }
//    }

    printf("=");
    i = 2;
    while (n > 1) {
        if (n % i == 0) {
            printf("%d", i);
            n = n / i;
            if (n>1)
                printf("*");
        } else
            i++;
    }
}
