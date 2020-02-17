/*(数制转换|M进制转换为N进制)
 *
 */

#include <iostream>
#include <cstdio>
#include <stack>
#include <string>
#include <cmath>

using namespace std;

int CharToInt(char c){  //字符转化为数字
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'a' && c <= 'z') {
        return c - 'a' + 10;
    } else
        return c - 'A' + 10;
}

int CharToTen(string str,int x){    //把x进制数str转化为10进制数
    int number = 0;
    int k = str.size() - 1;
    for (int i = 0; i < str.size(); ++i) {
        number += CharToInt(str[i]) * pow(x, k);
        k--;
    }
    return number;
}

stack<char> TenToB(int temp,int b){
    stack<char> stack;
    while (temp != 0) {
        int m = temp % b;
        if (m<=9) {
            stack.push(m + '0');
        } else
            stack.push(m - 10 + 'A');
        temp /= b;
    }
    return stack;
}

int main(){
    int a,b;
    string n;
    while (cin >> a) {
        cin >> n;
        cin >> b;
        int temp = CharToTen(n, a);
        stack<char> s = TenToB(temp, b);
        while (!s.empty()) {
            printf("%c", s.top());
            s.pop();
        }
        printf("\n");
    }
    return 0;
}