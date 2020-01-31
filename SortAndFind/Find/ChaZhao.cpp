/*(查找)
题目描述
输入数组长度 n 输入数组      a[1...n] 输入查找个数m 输入查找数字b[1...m]   输出 YES or NO  查找有则YES 否则NO 。
输入描述:
输入有多组数据。
每组输入n，然后输入n个整数，再输入m，然后再输入m个整数（1<=m,n<=100）。
输出描述:
如果在n个数组中输出YES否则输出NO。
示例1
输入
5
1 5 2 4 3
3
2 5 6
输出
YES
YES
NO
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100;

int arr[MAXN];

bool BinerySearch(int n,int target){ //二分查找
    int left = 0;
    int right = n - 1;
    while (left <= right) {
        int middle = (left + right) / 2;
        if (target > arr[middle]) {
            left = middle + 1;
        } else if (target < middle) {
            right = middle - 1;
        } else
            return true;
    }
    return false;
}
int main(){
    int n,m;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            scanf("%d", &arr[i]);
        }
        sort(arr, arr + n);
        scanf("%d", &m);
        int b[m];
        for (int j = 0; j < m; ++j) {
            scanf("%d", &b[j]);
        }
        for (int k = 0; k < m; ++k) {
            if (BinerySearch(n, b[k])) {
                printf("YES\n");
            } else{
                printf("NO\n");
            }
        }
    }
    return 0;
}