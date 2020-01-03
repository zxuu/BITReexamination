//
// Created by zxuu on 2020/1/3.
//
/*
 * 整数和
 * 编写程序，读入一个整数N。若N为非负数，则计算N 到2N 之间的整数和；若N为一个负数，则求2N 到N 之间的整数和。
 *
 * 输入描述：
 * 第一行表示样例数m，接下来m行每行一个整数N，N的绝对值不超过100。
 * 输出描述：
 * 输出m行，每行表示对应的题目所求。
 *
 * 示例
 * 输入：
 * 2
 * 2
 * -1
 * 输出：
 * 9
 * -3
 */
#include <stdio.h>
#include <math.h>
int func(int x){
    int sum = 0;
    for (int i = abs(x); i <= 2 * abs(x); i++) {
        sum += i;
    }
    if (x >= 0) {
        return sum;
    } else{
        return 0 - sum;
    }
}
int main(){
    int n = 0;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int j = 0; j < n; j++) {
        printf("%d\n", func(a[j]));
    }
    return 0;
}
