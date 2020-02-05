/*
题目描述
You are given a sequence of integer numbers. Zero-complexity transposition of the sequence is the reverse of this sequence. Your task is to write a program that prints zero-complexity transposition of the given sequence.
输入描述:
For each case, the first line of the input file contains one integer n-length of the sequence (0 ＜ n ≤ 10 000). The second line contains n integers numbers-a1, a2, …, an (-1 000 000 000 000 000 ≤ ai ≤ 1 000 000 000 000 000).
输出描述:
For each case, on the first line of the output file print the sequence in the reverse order.
示例1
输入
5
-3 4 6 -8 9
输出
9 -8 6 4 -3
 */

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

stack<long long > myStack;

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int i = 0; i < n; ++i) {
            long long k;
            scanf("%lld", &k);
            myStack.push(k);
        }
        while (!myStack.empty()) {
            printf("%lld ", myStack.top());
            myStack.pop();
        }
        printf("\n");
    }
    return 0;
}