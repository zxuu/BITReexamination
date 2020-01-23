/*
题目描述(反序数)
设N是一个四位数，它的9倍恰好是其反序数（例如：1234的反序数是4321）
求N的值
输入描述:
程序无任何输入数据。
输出描述:
输出题目要求的四位数，如果结果有多组，则每组结果之间以回车隔开。
示例1
输入
无
输出
无
 */
#include <iostream>
#include <cstdio>

int Reverse(int x){
    int result = 0;
    while (x != 0) {
        result = result*10 + x%10;
        x/=10;
    }
    return result;
}
int main(){
    for (int i = 1000; i <=9999; ++i) {
        if (i*9 == Reverse(i))
            printf("%d\n", i);
    }
    return 0;
}
