/*(十进制转化为任意进制)
题目描述
输入两个不超过整型定义的非负10进制整数A和B(<=231-1)，输出A+B的m (1 < m <10)进制数。
输入描述:
输入格式：测试输入包含若干测试用例。每个测试用例占一行，给出m和A，B的值。
当m为0时输入结束。
输出描述:
输出格式：每个测试用例的输出占一行，输出A+B的m进制数。
示例1
输入
8 1300 48
2 1 7
0
输出
2504
1000
 */

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

stack<int> TenTo(long long from,int x){  //把from转化为to进制
    stack<int> answer;
    while (from != 0) {
        answer.push(from % x);
        from /= x;
    }
    return answer;
}

int main(){
    int m;
    long long A, B;
    stack<int> result;
    while (scanf("%d", &m) != EOF) {
        if (m == 0)
            break;
        scanf("%d%d", &A, &B);
        result = TenTo(A + B, m);
        if (result.empty()) {
            printf("0\n");
            break;
        }
        while (!result.empty()) {
            printf("%d", result.top());
            result.pop();
        }
        printf("\n");
    }
    return 0;
}