/*(质因数的个数)
 *输入一个数，输出小于这个数的质数个数
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <cmath>

using namespace std;

const int MAXN = sqrt(1e9) + 1;
vector<int> prime;
bool isPrime[MAXN];

void Initial(){
    for (int i = 0; i < MAXN; ++i) {
        isPrime[i] = true;
    }
    isPrime[0] = false;
    isPrime[1] = false;
    for (int i = 2; i < MAXN; ++i) {
        if (!isPrime[i]) {
            continue;
        }
        prime.push_back(i);
        for (int j = i * i; j < MAXN; j += i) {
            isPrime[j] = false;
        }
    }
}

int main(){
    Initial();
    int n;
    while (scanf("%d", &n) != EOF) {
        int answer = 0;
        for (int i = 0; i < prime.size() && prime[i] < n; ++i) {
            int factor = prime[i];
            while (n%factor == 0) {   //不断试除
                n /= factor;
                answer++;
            }
        }
        if (n>1) {
            answer++;
        }
        printf("%d\n", answer);
    }
    return 0;
}