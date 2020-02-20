#include <iostream>
#include <cstdio>

using namespace std;

//快速幂
int FastExponentiation(int a, int b, int mod){
    int answer = 1;    //初始化为1
    while (b != 0) {    //不断将b转换为二进制
        if (b % 2 == 1) {    //若当前为1，累乘2^k次幂
            answer *= a;
            answer %= mod;    //求后三位
        }
        b /= 2;
        a *= a;     //a不断平方
        a %= mod;
    }
    return answer;
}

int main(){
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        if (a == 0 && b == 0) {
            break;
        }
        printf("%d\n", FastExponentiation(a, b, 1000));
    }
    return 0;
}