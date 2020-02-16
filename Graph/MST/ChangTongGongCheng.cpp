#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int MAXN = 100;

struct Edge {
    int from;
    int to;
    int lenght;
    bool operator< (const Edge& e) const{   //重载小于号
        return lenght < e.lenght;
    }
};

Edge edge[MAXN * MAXN];
int father[MAXN];
int height[MAXN];

void Init(int n){
    for (int i = 0; i <= n; ++i) {
        father[i]=i;
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
        } else {
            father[y] = x;
            height[x]++;
        }
    }
}

int Kruskal(int n,int edgeNumber){
    int minSum = 0;
    Init(n);
    sort(edge, edge + edgeNumber);
    for (int i = 0; i < edgeNumber; ++i) {
        Edge currentEge = edge[i];
        if (Find(currentEge.from) != Find(currentEge.to)) {
            Union(currentEge.from, currentEge.to);
            minSum += currentEge.lenght;
        }
    }
    return minSum;
}

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;
        int edgeNumber = n * (n - 1) / 2;
        for (int i = 0; i < edgeNumber; ++i) {
            scanf("%d%d%d", &edge[i].from, &edge[i].to, &edge[i].lenght);
        }
        int minLenght = Kruskal(n, edgeNumber);
        printf("%d\n", minLenght);
    }
    return 0;
}