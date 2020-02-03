/*(完数与盈数)
题目描述
一个数如果恰好等于它的各因子(该数本身除外)子和，如：6=3+2+1。则称其为“完数”；若因子之和大于该数，则称其为“盈数”。 求出2到60之间所有“完数”和“盈数”。
输入描述:
题目没有任何输入。
输出描述:
输出2到60之间所有“完数”和“盈数”，并以如下形式输出：
E: e1 e2 e3 ......(ei为完数)
G: g1 g2 g3 ......(gi为盈数)
其中两个数之间要有空格，行尾不加空格。
示例1
输入

输出

 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int func(int x){
    int sum = 0;
    for (int i = 1; i < x; ++i) {
        if (x % i == 0) {
            sum += i;
        }
    }
    if (sum == x) {
        return 1;   //如果是完数返回1
    } else if (sum > x) {
        return 2;   //如果是盈数返回2
    }
    return 0;   //都不是完数返回0
}

int main(){
    vector<int> wanInt;
    vector<int> yingInt;
    for (int i = 3; i < 61; ++i) {
        int k = func(i);
        if (k == 1) {
            wanInt.push_back(i);
        } else if (k == 2) {
            yingInt.push_back(i);
        }
    }
    printf("E:");
    for (int j = 0; j < wanInt.size(); ++j) {
        printf(" %d", wanInt[j]);
    }
    printf("\n");
    printf("G:");
    for (int l = 0; l < yingInt.size(); ++l) {
        printf(" %d", yingInt[l]);
    }
    printf("\n");
    return 0;
}