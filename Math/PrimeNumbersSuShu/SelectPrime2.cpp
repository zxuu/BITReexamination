/*(第k个素数|素数筛选法的应用)
题目描述
Output the k-th prime number.
输入描述:
k≤10000
输出描述:
The k-th prime number.
示例1
输入
3
7
输出
5
17
 */

#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

const int MAXN = 10000;
bool isPrime[MAXN];
int prime[MAXN];

void Initial(){
    for (int i = 0; i < MAXN; ++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    int k = 0;
    for (int i = 2; i < MAXN; ++i) {
        if (!isPrime[i]) {
            continue;
        }
        prime[k++] = i;
        for (int j = i * i; j < MAXN; j += i) {
            isPrime[j] = false; //指数的倍数为非质数
        }
    }
}

int main(){
    int x;
    Initial();
    while (scanf("%d", &x) != EOF) {
        printf("%d\n", prime[x-1]);
    }
    return 0;
}