/*(用优先队列解决哈夫曼树)
题目描述
哈夫曼树，第一行输入一个数n，表示叶结点的个数。需要用这些叶结点生成哈夫曼树，根据哈夫曼树的概念，这些结点有权值，即weight，题目需要输出所有结点的值与权值的乘积之和。
输入描述:
输入有多组数据。
每组第一行输入一个数n，接着输入n个叶节点（叶节点权值不超过100，2<=n<=1000）。
输出描述:
输出权值。
示例1
输入
5
1 2 2 5 9
输出
37
 */

/*
 * 优先队列解决哈夫曼树的问题真到位呀！
 */
#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        priority_queue<int, vector<int>, greater<int> > myPriorityQueue;
        while (n--) {
            int x;
            cin>>x;
            myPriorityQueue.push(x);
        }
        int sum = 0;
        while (myPriorityQueue.size() > 1) {
            int a = myPriorityQueue.top();
            myPriorityQueue.pop();
            int b = myPriorityQueue.top();
            myPriorityQueue.pop();
            sum += a + b;
            myPriorityQueue.push(a + b);
        }
        printf("%d\n", sum);
    }
    return 0;
}