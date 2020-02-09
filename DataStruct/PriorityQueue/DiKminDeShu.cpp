/*(第k小的数)
题目描述
查找一个数组的第K小的数，注意同样大小算一样大。 如  2 1 3 4 5 2 第三小数为3。
输入描述:
输入有多组数据。
每组输入n，然后输入n个整数(1<=n<=1000)，再输入k。
输出描述:
输出第k小的整数。
示例1
输入
6
2 1 3 5 2 2
3
输出
3
 */

#include <iostream>
#include <cstdio>
#include <queue>

using namespace  std;

int main(){
    int n;
    while (cin >> n) {
        priority_queue<int, vector<int>, greater<int> > myPriorityQueue;
        for (int j = 0; j < n; ++j) {
            int temp;
            cin >> temp;
            myPriorityQueue.push(temp);
        }
        int k, i = 1;
        cin >> k;
        if (k == 1) {
            printf("%d\n", myPriorityQueue.top());
            return 0;
        }
        int p = myPriorityQueue.top();
        myPriorityQueue.pop();
        int t = 0;
        while (!myPriorityQueue.empty()) {
            t = myPriorityQueue.top();
            if (t != p) {
                p = t;
                i++;
                if (i == k) {
                    printf("%d\n", t);
                    break;
                }
            }
            myPriorityQueue.pop();
        }
    }
    return 0;
}