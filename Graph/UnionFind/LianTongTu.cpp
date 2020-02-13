/*(连通图|还是不断的连通、最后判断有几个集合)
题目描述
    给定一个无向图和其中的所有边，判断这个图是否所有顶点都是连通的。
输入描述:
    每组数据的第一行是两个整数 n 和 m（0<=n<=1000）。n 表示图的顶点数目，m 表示图中边的数目。随后有 m 行数据，每行有两个值 x 和 y（0<x, y <=n），表示顶点 x 和 y 相连，顶点的编号从 1 开始计算。输入不保证这些边是否重复。
输出描述:
    对于每组输入数据，如果所有顶点都是连通的，输出"YES"，否则输出"NO"。
示例1
输入
4 3
1 2
2 3
3 2
3 2
1 2
2 3
0 0
输出
NO
YES
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000;

int father[MAXN];
int height[MAXN];

void Initial(int n){       //父节点赋初值
    for (int i = 0; i <= n; ++i) {
        father[i] = i;  //每个节点的父节点是自己
        height[i] = 0;
    }
}

int Find(int x){
    if (x != father[x]) //路径压缩
        father[x] = Find(father[x]);
    return father[x];
}

void Union(int x,int y){    //合并集合
    x = Find(x);
    y = Find(y);
    if (x != y) {   //矮树作为高树的子树
        if (height[x] < height[y]) {
            father[x] = y;
        } else if (height[x] > height[y]) {
            father[y] = x;
        } else{
            father[y] = x;
            height[x]++;
        }
    }
}

int main(){
    int n, m;
    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;
        scanf("%d", &m);
        Initial(n);
        while (m--) {
            int x,y;
            scanf("%d", &x);
            scanf("%d", &y);
            Union(x, y);
        }
        int number = 0;
        for (int j = 1; j <= n; ++j) {
            if (j == Find(j))
                number++;
        }
        if (number == 1)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}