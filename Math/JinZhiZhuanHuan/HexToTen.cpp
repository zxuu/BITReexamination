/*(16进制转化为10进制)
题目描述
写出一个程序，接受一个十六进制的数值字符串，输出该数值的十进制字符串(注意可能存在的一个测试用例里的多组数据)。

输入描述:
输入一个十六进制的数值字符串。

输出描述:
输出该数值的十进制字符串。

示例1
输入
0xA
输出
10
 */

#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

double CharToInt(char c){
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else{
        return c - 'A' + 10;
    }
}

int main(){
    string str;
    while (cin >> str) {
        int number = 0;
        int n = str.size() - 3;
        for (int i = 2; i < str.size(); ++i) {
            number += CharToInt(str[i]) * pow(16.0, n);
            n--;
        }
        printf("%d\n", number);
    }
    return 0;
}


//#include <stdio.h>
//int main(void) {
//    int num = 0;
//    while (scanf ("%x", &num))
//        printf("%d\n",  num);
//    return 0;
//}
