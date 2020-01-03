//编写程序，计算下列分段函数y=f(x)的值。
//当 0<= x <2，y= -x+2.5；
//当 2<= x <4，y=2-1.5(x-3)(x-3)；
//当 4<= x <6，y=x/2-1.5；

//输入第一行为整数m表示样例数，接下来有m行每行一个整数x。
//输出m行分别表示对应的y值，保留小数点后一位小数。
/* 输入
2
1
3
*/
/* 输出
y=1.5
y=2.0
*/
#include <stdio.h>

float func(int x){
    if (x >= 0 && x < 2) {
        return 2.5 - x;
    } else if (2 <= x && x < 4) {
        return 2.0 - 1.5 * (x - 3) * (x - 3);
    } else if (4 <= x && x < 6) {
        return x / 2.0 - 1.5;
    }
    return 6.0;
}
int main() {
    int n=0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
    }
    for (int j = 0; j < n; ++j) {
        printf("y=%.1f\n", func(a[j]));
    }
    return 0;
}


