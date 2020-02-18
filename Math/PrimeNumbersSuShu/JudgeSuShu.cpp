/*(判定素数)
题目描述
给出n个正整数，任取两个数分别作为分子和分母组成最简真分数，编程求共有几个这样的组合。
输入描述:
每组包含n（n<=600）和n个不同的整数，整数大于1且小于等于1000。
输出描述:
每行输出最简真分数组合的个数。
示例1
输入
7
3 5 7 9 11 13 15
3
2 4 5
0
输出
17
2
 */

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool Judge(int x){  //判断是否为质数
    if (x<2)
        return false;
    int bound = sqrt(x);    //确定判断上界
    for (int i = 2; i <= bound; ++i) {
        if (x % i == 0) {
            return false;
        }
    }
    return true;
}

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        if (Judge(n)) {
            printf("yes\n");
        } else
            printf("no\n");
    }
    return 0;
}