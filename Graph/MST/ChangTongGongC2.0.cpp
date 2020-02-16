/*(还是畅通工程|最小生成树、只不过一些点已经连上了)
题目描述
    省政府“畅通工程”的目标是使全省任何两个村庄间都可以实现公路交通（但不一定有直接的公路相连，只要能间接通过公路可达即可）。现得到城镇道路统计表，表中列出了任意两城镇间修建道路的费用，以及该道路是否已经修通的状态。现请你编写程序，计算出全省畅通需要的最低成本。
输入描述:
    测试输入包含若干测试用例。每个测试用例的第1行给出村庄数目N ( 1< N < 100 )；随后的 N(N-1)/2 行对应村庄间道路的成本及修建状态，每行给4个正整数，分别是两个村庄的编号（从1编号到N），此两村庄间道路的成本，以及修建状态：1表示已建，0表示未建。

    当N为0时输入结束。
输出描述:
    每个测试用例的输出占一行，输出全省畅通需要的最低成本。
示例1
输入
3
1 2 1 0
1 3 2 0
2 3 4 0
3
1 2 1 0
1 3 2 0
2 3 4 1
3
1 2 1 0
1 3 2 1
2 3 4 1
0
输出
3
1
0
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100;

struct Edge {
    int from;
    int to;
    int lenght;
    bool operator< (const Edge& e) const {  //重载小于号
        return lenght < e.lenght;
    }
};

Edge edge[MAXN * MAXN];
int father[MAXN];
int height[MAXN];

void Initial(int n){
    for (int i = 0; i <= n; ++i) {
        father[i] = i;
        height[i] = 0;
    }
}

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

int Kruskal(int n, int edgeNumber){
    int minSum = 0;
    Initial(n);
    sort(edge, edge + edgeNumber);
    for (int i = 0; i < edgeNumber; ++i) {
        Edge e = edge[i];
        if (Find(e.from) != Find(e.to)) {
            Union(e.from, e.to);
            minSum += e.lenght;
        }
    }
    return minSum;
}

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n==0)
            break;
        int edgeNumber = n * (n - 1) / 2;
        for (int i = 0; i < edgeNumber; ++i) {
            int status;
            scanf("%d%d%d%d", &edge[i].from, &edge[i].to, &edge[i].lenght, &status);
            if (status == 1)
                edge[i].lenght = 0;
        }
        int minLenght = Kruskal(n, edgeNumber);
        printf("%d\n", minLenght);
    }
    return 0;
    //so tama whatjiaSSD
}