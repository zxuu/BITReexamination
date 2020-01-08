//
// Created by zxuu on 2020/1/8.
//
/*
 * 题目描述:球的计算
输入球的中心点和球上某一点的坐标，计算球的半径和体积。
输入描述:
输入第一行为样例数m，接下来m行每行6个整数，分别表示球心和球上一点的坐标。
输出描述:
输出m行，每行2个浮点数分别表示球的半径和体积，保留到小数点后两位。
示例1
输入
1
0 0 0 1 0 0
输出
1.00 4.19
 */
#include <stdio.h>
#include <math.h>
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int x1,y1,z1,x2,y2,z2;
        scanf("%d%d%d%d%d%d", &x1, &y1, &z1, &x2, &y2, &z2);
        double r = sqrt((x1 - x2) * (x1 - x2) +
                        (y1 - y2) * (y1 - y2) + (z1 - z2) * (z1 - z2));
        double v = 3.1415926*4/3 * r * r * r;
        printf("%.2f %.2f", r, v);
    }
}

