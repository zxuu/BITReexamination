/*(约数的个数)
 *一个数的约数个数
 * 题目描述
输入n个整数,依次输出每个数的约数的个数
输入描述:
输入的第一行为N，即数组的个数(N<=1000)
接下来的1行包括N个整数，其中每个数的范围为(1<=Num<=1000000000)
当N=0时输入结束。
输出描述:
可能有多组输入数据，对于每组输入数据，
输出N行，其中每一行对应上面的一个数的约数的个数。
示例1
输入
5
1 3 4 6 12
输出
1
2
3
4
6
 */

#include <iostream>
#include <cstdio>

using namespace std;

int numOfDivisor(int x){
    int sum = 0, i;
    for (i = 1; i*i < x; ++i) {
        if (x % i == 0) {
            sum += 2;
        }
    }
    if (i * i == x) {
        sum++;
    }
    return sum;
}

int main(){
    int n;
    while (cin >> n) {
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            cout << numOfDivisor(x) << endl;
        }
    }
    return 0;
}