/*
 * top()访问当前队列中优先级最高的元素
 */

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

priority_queue<int> myPriorityQueue;

int main(){
    cout << "Size:" << myPriorityQueue.size() << endl;
    myPriorityQueue.push(20);
    myPriorityQueue.push(100);
    myPriorityQueue.push(30);
    myPriorityQueue.push(30);
    cout << "Top: " << myPriorityQueue.top() << endl;
    int sum;
    while (!myPriorityQueue.empty()) {
        sum += myPriorityQueue.top();
        cout << "Top: " << myPriorityQueue.top() << endl;
        myPriorityQueue.pop();
    }
    cout << "Sum: " << sum << endl;
    return 0;
}