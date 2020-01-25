/*
打印所有不超过256，其平方具有对称性质的数。如2，11就是这样的数，因为2*2=4，11*11=121。

输入描述:
无任何输入数据


输出描述:
输出具有题目要求的性质的数。如果输出数据不止一组，各组数据之间以回车隔开。
示例1
输入
无
输出
无
 */
#include <iostream>
#include <cstdio>

int Reverse(int x){
    int result =0;
    while (x != 0) {
        result = result*10 + x%10;
        x /= 10;
    }
    return result;
}
int main(){
    for (int i = 0; i < 256; ++i) {
        if (i*i == Reverse(i*i))
            printf("%d\n", i);
    }
}

