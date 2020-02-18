/*(素数筛选法)
题目描述
输入一个整数n(2<=n<=10000)，要求输出所有从1到这个整数之间(不包括1和这个整数)个位为1的素数，如果没有则输出-1。
输入描述:
输入有多组数据。
每组一行，输入n。
输出描述:
输出所有从1到这个整数之间(不包括1和这个整数)个位为1的素数(素数之间用空格隔开，最后一个素数后面没有空格)，如果没有则输出-1。
示例1
输入
100
输出
11 31 41 61 71
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 1001;

vector<int> prime;  //保存质数
bool isPrime[MAXN]; //是否为质数

void Initial(){
    for (int i = 0; i < MAXN; ++i) {    //初始化
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i < MAXN; ++i) {    //不是质数则跳过
        if (!isPrime[i]) {
            continue;
        }
        prime.push_back(i);
        for (int j = i * i; j < MAXN; j += i) { //质数的倍数为非质数
            isPrime[j] = false;
        }
    }
}

int main(){
    Initial();
    int n;
    while (scanf("%d", &n) != EOF) {
        bool isOutput = false;
        for (int i = 0; i < prime.size() && prime[i] < n; ++i) {
            if (prime[i] %10 == 1) {
                isOutput = true;
                printf("%d ", prime[i]);
            }
        }
        if (!isOutput) {
            printf("-1");
        }
        printf("\n");
    }
    return 0;
}