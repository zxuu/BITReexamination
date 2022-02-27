//
// 输出500以内的水仙花数：水仙花数是指一个三位数，其各位数字立方和等于该数
// 本身。例如，153=1^3+5^3+3^3
//
#include <stdio.h>
void  main(){
    int a,b,c;
    int t;
    for (int i = 100; i < 500; ++i) {
        c=i%10;//个位
        t=i/10;//十位
        b=t%10;
        a=t/10;//百位
        if (a * a * a + b * b * b + c * c * c == i) {
            printf("%5d", i);
        }
    }
}

