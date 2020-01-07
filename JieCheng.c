//
// Created by zxuu on 2020/1/7.
//
/*题目：阶乘
请编写一个程序，从键盘上输入n（n 的范围是1～20），求n 的阶乘。
输入描述:
输入第一行为样例数m，接下来m行每行一个整数n，n不超过20。
输出描述:
输出m行表示对应的n的阶乘。

示例1
输入
1
3
输出
6
 */
#include <stdio.h>
int main(){
    int m, n;
    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d",&n);
        long int sum = 1;
        for (int j = n; j > 1; j--) {
            sum = sum * j;
        }
        printf("%ld\n",sum);
    }
}
