/*(第一题|求连通分支数)
题目描述
该题的目的是要你统计图的连通分支数。
输入描述:
每个输入文件包含若干行，每行两个整数i,j，表示节点i和j之间存在一条边。
输出描述:
输出每个图的联通分支数。
示例1
输入
1 4
4 3
5 5
输出
2
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 10;

int father[MAXN];
int height[MAXN];

int Find(int x){
    if (x != father[x]) {
        father[x] = Find(father[x]);
    }
    return father[x];
}

void Union(int x,int y){
    x = Find(x);
    y = Find(y);
    if (x != y) {
        if (height[x] < height[y]) {
            father[x] = y;
        } else if (height[y] < height[x]) {
            father[y] = x;
        } else{
            father[y] = x;
            height[x]++;
        }
    }
}

void Initial(){
    for (int i = 0; i < MAXN; ++i) {
        father[i] = i;
        height[i] = 0;
    }
}

int main(){
    int x,y;
    Initial();
    while (cin >> x >> y) {
        Union(x, y);
    }
    int number = 0;
    for (int i = 0; i < MAXN; ++i) {
        if (Find(i) == i) {
            number++;
        }
    }
    cout << number << endl;
    return 0;
}