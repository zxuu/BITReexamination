/*(特殊乘法)
题目描述
写个算法，对2个小于1000000000的输入，求结果。 特殊乘法举例：123 * 45 = 1*4 +1*5 +2*4 +2*5 +3*4+3*5
输入描述:
两个小于1000000000的数
输出描述:
输入可能有多组数据，对于每一组数据，输出Input中的两个数按照题目要求的方法进行运算后得到的结果。
示例1
输入
123 45
输出
54
 */

#include <string>
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    string str1, str2;
    while (cin >> str1 >> str2) {
        int answer = 0;
        for (int i = 0; i < str1.size(); ++i) {
            for (int j = 0; j < str2.size(); ++j) {
                answer += (str1[i] - '0') * (str2[j] - '0');    //很好
            }
        }
        printf("%d\n", answer);
    }
    return 0;
}