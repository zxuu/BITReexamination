/*(判断是否是一棵树)
题目描述
A tree is a well-known data structure that is either empty (null, void, nothing) or is a set of one or more nodes connected by directed edges between nodes satisfying the following properties. There is exactly one node, called the root, to which no directed edges point. Every node except the root has exactly one edge pointing to it. There is a unique sequence of directed edges from the root to each node. For example, consider the illustrations below, in which nodes are represented by circles and edges are represented by lines with arrowheads. The first two of these are trees, but the last is not.

In this problem you will be given several descriptions of collections of nodes connected by directed edges. For each of these you are to determine if the collection satisfies the definition of a tree or not.
输入描述:
The input will consist of a sequence of descriptions (test cases) followed by a pair of negative integers. Each test case will consist of a sequence of edge descriptions followed by a pair of zeroes Each edge description will consist of a pair of integers; the first integer identifies the node from which the edge begins, and the second integer identifies the node to which the edge is directed. Node numbers will always be greater than zero and less than 10000.
输出描述:
For each test case display the line "Case k is a tree." or the line "Case k is not a tree.", where k corresponds to the test case number (they are sequentially numbered starting with 1).
示例1
输入
6 8  5 3  5 2  6 4
5 6  0 0

8 1  7 3  6 2  8 9  7 5
7 4  7 8  7 6  0 0

3 8  6 8  6 4
5 3  5 6  5 2  0 0
-1 -1
输出
Case 1 is a tree.
Case 2 is a tree.
Case 3 is not a tree.
 */

#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000;

int father[MAXN];
int height[MAXN];
int inDegree[MAXN];
bool visited[MAXN];

void Initial(){
    for (int i = 0; i < MAXN; ++i) {
        father[i] = i;
        height[i] = 0;
        visited[i] = false;
        inDegree[i] = 0;
    }
}

int Find(int x){    //寻找父节点
    if (x != father[x]) {   //路径压缩
        father[x] = Find(father[x]);
    }
    return father[x];
}

void Union(int x,int y){    //合并集合
    x = Find(x);
    y = Find(y);
    if (x != y) {
        if (height[x] < height[y]) {
            father[x] = y;
        } else if (height[x] > height[y]) {
            father[y] = x;
        } else {
            father[y] = x;
            height[x]++;
        }
    }
}

bool IsTree(){
    bool flag = true;
    int component = 0;  //连通分量数目
    int root = 0;   //根节点数目
    for (int i = 0; i < MAXN; ++i) {
        if (!visited[i]) {  //如果节点没有被访问的话，就什么也不访问
            continue;
        }
        if (father[i] == i) //如果单节点就是跟
            component++;    //集合数加一
        if (inDegree[i] ==0) {
            root++;
        } else if (inDegree[i]>1) {
            flag = false;
        }
    }
    if (component != 1 ||root!=1) { //不符合树的定义
        flag = false;
    }
    if (component==0&&root==0) {    //空集也是树
        flag = true;
    }
    return flag;
}

int main(){
    int x,y;
    int caseNumber = 0;
    Initial();
    while (scanf("%d%d", &x, &y) != EOF) {
        if (x==-1&&y==-1)
            break;
        if (x==0 && y==0) {
            if (IsTree()) {
                printf("Case %d is a tree.\n", ++caseNumber);
            } else{
                printf("Case %d is not a tree.\n", ++caseNumber);
            }
            Initial();
        } else{
            Union(x, y);
            inDegree[y]++;
            visited[x] = true;
            visited[y] = true;
        }
    }
    return 0;
}