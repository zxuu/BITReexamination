/*
题目描述(小白鼠排队)
N只小白鼠(1 <= N <= 100)，每只鼠头上戴着一顶有颜色的帽子。现在称出每只白鼠的重量，要求按照白鼠重量从大到小的顺序输出它们头上帽子的颜色。帽子的颜色用“red”，“blue”等字符串来表示。不同的小白鼠可以戴相同颜色的帽子。白鼠的重量用整数表示。
输入描述:
多案例输入，每个案例的输入第一行为一个整数N，表示小白鼠的数目。
下面有N行，每行是一只白鼠的信息。第一个为不大于100的正整数，表示白鼠的重量，；第二个为字符串，表示白鼠的帽子颜色，字符串长度不超过10个字符。

注意：白鼠的重量各不相同。
输出描述:
每个案例按照白鼠的重量从大到小的顺序输出白鼠的帽子颜色。
示例1
输入
3
30 red
50 blue
40 green
输出
blue
green
red
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Mouse{
    int weight;
    string color;
};

bool Compare(Mouse x,Mouse y){
    return x.weight > y.weight;
}
int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        Mouse m[n];
        for (int i = 0; i < n; ++i) {
            cin >> m[i].weight >> m[i].color;
        }
        sort(m, m + n, Compare);
        for (int j = 0; j < n; ++j) {
            cout << m[j].color << endl;
        }
    }
    return 0;
}