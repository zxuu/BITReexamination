/*(十进制转换为二进制)
题目描述
大家都知道，数据在计算机里中存储是以二进制的形式存储的。 有一天，小明学了C语言之后，他想知道一个类型为unsigned int 类型的数字，存储在计算机中
的二进制串是什么样子的。 你能帮帮小明吗？并且，小明不想要二进制串中前面的没有意义的0串，即要去掉前导0。
输入描述:
每行有一个数字n（0<=n<=10^8），表示要求的二进制串。
输出描述:
输出共T行。每行输出求得的二进制串。
示例1
输入
5
23
535
2624
56275
989835
输出
10111
1000010111
101001000000
1101101111010011
11110001101010001011
 */

#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        stack<int> binary;
        while(n!=0) {
            binary.push(n % 2);
            n /= 2;
        }
        while (!binary.empty()) {
            printf("%d", binary.top());
            binary.pop();
        }
        printf("\n");
    }
    return 0;
}