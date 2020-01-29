/*
题目描述
    对输入的n个数进行排序并输出。
输入描述:
    输入的第一行包括一个整数n(1<=n<=100)。
    接下来的一行包括n个整数。
输出描述:
    可能有多组测试数据，对于每组数据，将排序后的n个整数输出，每个数后面都有一个空格。
    每组测试数据的结果占一行。
示例1
输入
4
1 4 3 2
输出
1 2 3 4
 */

#include <iostream>
#include <cstdio>
#include <algorithm>
using  namespace std;

const int MAXN = 100;
int arr[MAXN];

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + n);
        for (int j = 0; j < n; ++j) {
            printf("%d ", arr[j]);
        }
        printf("\n");
    }
    return 0;
}