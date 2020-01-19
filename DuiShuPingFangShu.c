/*
 题目描述
打印所有不超过n（n<256）的，其平方具有对称性质的数。如11*11=121。
输入描述:
无
输出描述:
每行一个数，表示对称平方数。
示例1
输入
无
输出
无
 */
#include<stdio.h>
#include<stdlib.h>

int func(int x){
    int y = 0;
    while (x) {
        y = y * 10 + x % 10;
        x /= 10;
    }
    return y;
}
int main(){
    for (int i = 1; i < 256; i++) {
        if (i * i == func(i * i)) {
            printf("%d\n", i);
        }
    }
}

