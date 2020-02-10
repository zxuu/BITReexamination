/*(子串统计)
题目描述
给出一个01字符串（长度不超过100），求其每一个子串出现的次数。
输入描述:
输入包含多行，每行一个字符串。
输出描述:
对每个字符串，输出它所有出现次数在1次以上的子串和这个子串出现的次数，输出按字典序排序。
示例1
输入
10101
输出
0 2
01 2
1 3
10 2
101 2
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

int main(){
    string str;
    while (cin >> str) {
        map<string,int> number;
        for (int i = 0; i <= str.size(); ++i) {
            for (int j = 0; j < i; ++j) {
                string key = str.substr(j, i - j);
                number[key]++;
            }
        }
        //map内部按红黑树排序，内部已按关键字排好序！！！
        map<string,int>::iterator it;
        for (it = number.begin(); it != number.end(); it++) {
            if (it->second>1)
                cout << it->first << " " << it->second << endl;
        }
    }
    return 0;
}