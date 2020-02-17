/*(M进制转换为N进制)
 *
 */

#include <iostream>
#include <cstdio>
#include <stack>
#include <string>

using namespace std;

char IntToChar(int x){    //数字转字符
    if (x < 10) {
        return x + '0';
    } else
        return x - 10 + 'a';    //数字大于10的话
}

int CharToInt(char c){    //字符转数字
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else
        return c - 'A' + 10;
}

int main(){
    int m, n;
    scanf("%d%d", &m, &n);
    string str;
    cin >> str;
    long long number = 0;
    //m进制转10进制
    for (int i = 0; i < str.size(); ++i) {
        number *= m;
        number += CharToInt(str[i]);
    }

    stack<char> answer;
    while (number!=0) { //十进制转化为n进制
        answer.push(IntToChar(number % n));
        number /= n;
    }
    while (!answer.empty()) {
        printf("%c", answer.top());
        answer.pop();
    }
    return 0;
}