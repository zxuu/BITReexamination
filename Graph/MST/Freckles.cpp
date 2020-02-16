/*(最小生成)

 */
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAXN = 100;

struct Node {
    float x;
    float y;
};

struct Edge{
    int from;
    int to;
    float lenght;
    bool operator< (const Edge& e) const {
        return lenght < e.lenght;
    }
};

Edge edge[MAXN * MAXN];
int father[MAXN];
int height[MAXN];

void Initial(int n){
    for (int i = 0; i < n; ++i) {
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
        } else {
            father[y] = x;
            height[x]++;
        }
    }
}

float Kruskal(int n,int edgeNumber){
    float minSum = 0;
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
        Node nodes[n];
        for (int i = 0; i < n; ++i) {
            scanf("%f%f", &nodes[i].x, &nodes[i].y);
        }
        int edgeNumber = n * (n - 1) / 2;
        int k = 0;
        for (int j = 0; j < n-1; ++j) {
            for (int i = j + 1; i < n; ++i) {
                edge[k].from = j;
                edge[k].to = i;
                edge[k].lenght = sqrt((nodes[j].x - nodes[i].x)
                                      * (nodes[j].x - nodes[i].x) + (nodes[j].y - nodes[i].y)
                                                                    * (nodes[j].y - nodes[i].y));
                k++;
            }
        }
        float minSum = Kruskal(n, edgeNumber);
        printf("%.2f\n", minSum);
    }
    return 0;
}