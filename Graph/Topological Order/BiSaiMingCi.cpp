/*
 * 拓扑排序 && 从小到大输出
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int MAXN = 500;

vector<int> graph[MAXN];
int inDegree[MAXN];

vector<int> Topological(int n){
    vector<int> topology;
    priority_queue<int, vector<int>, greater<int> > node;
    for (int i = 1; i <= n; ++i) {
        if (inDegree[i]==0)
            node.push(i);
    }
    while (!node.empty()) {
        int u = node.top();
        node.pop();
        topology.push_back(u);  //加入拓扑序列
        for (int i = 0; i < graph[u].size(); ++i) {
            int v = graph[u][i];
            inDegree[v]--;
            if (inDegree[v] == 0) {
                node.push(v);
            }
        }
    }
    return topology;
}

int main(){
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        memset(graph, 0, sizeof(graph));
        memset(inDegree, 0, sizeof(inDegree));
        while (m--) {
            int from, to;
            scanf("%d%d", &from, &to);
            graph[from].push_back(to);
            inDegree[to]++;
        }
        vector<int> answer = Topological(n);
        for (int i = 0; i < answer.size(); ++i) {
            if (i==0) {
                printf("%d", answer[i]);
            } else
                printf(" %d", answer[i]);
        }
        printf("\n");
    }
    return 0;
}