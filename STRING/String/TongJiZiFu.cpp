/*(统计字符)
题目描述
    统计一个给定字符串中指定的字符出现的次数。
输入描述:
    测试输入包含若干测试用例，每个测试用例包含2行，第1行为一个长度不超过5的字符串，第2行为一个长度不超过80的字符串。注意这里的字符串包含空格，即空格也可能是要求被统计的字符之一。当读到'#'时输入结束，相应的结果不要输出。
输出描述:
    对每个测试用例，统计第1行中字符串的每个字符在第2行字符串中出现的次数，按如下格式输出：
    c0 n0
    c1 n1
    c2 n2
    ...
    其中ci是第1行中第i个字符，ni是ci出现的次数。
示例1
输入
I
THIS IS A TEST
i ng
this is a long test string
#
输出
I 2
i 3
  5
n 2
g 2
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>

using namespace std;

int number[128];    //标记数组!!!

int main(){
    string str1,str2;
    while (getline(cin, str1)) {
        if (str1 == "#") {
            break;
        }
        getline(cin, str2);
        memset(number, 0, sizeof(number));  //初始化数组
        for (int i = 0; i < str2.size(); ++i) {
            number[str2[i]]++;
        }
        for (int j = 0; j < str1.size(); ++j) {
            printf("%c %d\n", str1[j], number[str1[j]]);
        }
    }
    return 0;
}
