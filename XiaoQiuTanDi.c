/*
 * 题目描述:弹地小球
一个小球，从高为H的地方下落，下落弹地之后弹起高度为下落时的一半，比如第一次弹起高度为H/2，如此往复，计算从小球H 高度下落到第n 次弹地往返的总路程。
输入描述:
输入第一行为样例数m，接下来m行每行两个整数H和n，n不超过5。
输出描述:
输出m行，表示所求总路程，结果保留小数点后两位。
示例1
输入
1
5 2
输出
10.00
 */
#include <stdio.h>
int main(){
    int m;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        float h, s=0.0;
        int n;
        scanf("%f%d", &h, &n);
        float hh = h;
        for (int j = 0; j < n - 1; j++) {
            s += h;
            h /= 2;
        }
        printf("%.2f\n", s + hh);
    }
}
