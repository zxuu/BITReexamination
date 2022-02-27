//
// 最大公约数最小公倍数
//
#include <stdio.h>
void main(){
    int GongYueShu(int, int);
    int a, b;
    scanf("%d %d", &a, &b);
    printf("%d\n", GongYueShu(b, a));
}

int GongYueShu(int b,int a){
    int t;
    if (b > a) {    //B小A大
        t = b;
        b = a;
        a = t;
    }
//    t = a % b;
    while ((a%b) != 0) {
//        t = a % b;
        a = b;
        b = a % b;
    }
    return b;
}

