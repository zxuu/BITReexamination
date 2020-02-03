#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

queue<int> myQueue;

int main(){
    for (int i = 0; i < 10; ++i) {
        myQueue.push(i);
    }
    printf("front:%d\n", myQueue.front());
    printf("back:%d\n", myQueue.back());
    int sum = 0;
    while (!myQueue.empty()) {
        sum += myQueue.front();
        myQueue.pop();
    }
    printf("sum:%d\n", sum);
    if (myQueue.empty()) {
        printf("is empty\n");
    }
    return 0;
}