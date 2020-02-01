/*
题目描述
在一个整数数组上，对于下标为i的整数，如果它大于所有它相邻的整数， 或者小于所有它相邻的整数，则称为该整数为一个极值点，极值点的下标就是i。
输入描述:
第一行是此数组的元素个数k(4<k<80)，第二行是k个整数，每两个整数之间用空格分隔。
输出描述:
每个案例输出为n行：每行对应于相应数组的所有极值点下标值，下标值之间用空格分隔。
示例1
输入
3
10
10 12 12 11 11 12 23 24 12 12
15
12 12 122 112 222 211 222 221 76 36 31 234 256 76 76
15
12 14 122 112 222 222 222 221 76 36 31 234 256 76 73
输出
0 7
2 3 4 5 6 10 12
0 2 3 10 12 14
 */

#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        int data[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &data[i]);
        }
        if (data[0] != data[1])
            printf("0 ");
        for (int j = 1; j < n-1; ++j) {
            if((data[j]<data[j-1]&&data[j]<data[j+1])
            || (data[j]>data[j-1]&&data[j]>data[j+1]))
                printf("%d ", j);
        }
        if (data[n-2] != data[n-1])
            printf("%d ", n - 1);
        printf("\n");
    }
    return 0;
}