/*(学生信息查询)
题目描述
输入N个学生的信息，然后进行查询。
输入描述:
输入的第一行为N，即学生的个数(N<=1000)
接下来的N行包括N个学生的信息，信息格式如下：
01 李江 男 21
02 刘唐 男 23
03 张军 男 19
04 王娜 女 19
然后输入一个M(M<=10000),接下来会有M行，代表M次查询，每行输入一个学号，格式如下：
02
03
01
04
输出描述:
输出M行，每行包括一个对应于查询的学生的信息。
如果没有对应的学生信息，则输出“No Answer!”
示例1
输入
4
01 李江 男 21
02 刘唐 男 23
03 张军 男 19
04 王娜 女 19
5
02
03
01
04
03

 输出
02 刘唐 男 23
03 张军 男 19
01 李江 男 21
04 王娜 女 19
03 张军 男 19
 */

#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<string, string> myMap;

int main(){
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; ++i) {
        string str;
        getline(cin, str);
        int pos = str.find(" ");
        string key = str.substr(0, pos);
        myMap[key] = str;
    }
    int m;
    scanf("%d", &m);
    for (int j = 0; j < m; ++j) {
        string key;
        cin >> key;
        string answer = myMap[key];
        if (answer == "") {
            answer = "No Answer!";
        }
        cout << answer << endl;
    }
    return 0;
}