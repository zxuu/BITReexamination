//
// 求满数：有两个数，每一个数的所有约数的和（除了本身外）等于对方，则称这两个数为互满数。
// 求3000以内的所有互满数。求满数的函数是func()
//
#include <stdio.h>
int k[40];
#define  N 3000
int func(int j){    //J的满数
    int i, s;
    s = 0;
    for (i = 1; i < j; i++) {
        if (j % i == 0) {
            s += i;
        }
    }
    return s;
}
void main(){
    int s1, s2;
    for (int m = 2; m < N; ++m) {   //判断m,i是否为互满数
        s1 = func(m);
        for (int i = m + 1; i < N; ++i) {
            s2 = func(i);
            if (s1 == s2) {
                printf("%d,%d\n", m, i);
            }
        }
    }
}
