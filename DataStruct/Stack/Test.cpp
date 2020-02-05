#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

stack<int> myStack;
int main(){
    for (int i = 0; i < 10; ++i) {
        myStack.push(i);
    }
    printf("Stack_Size:%d\n", myStack.size());
    int sum = 0;
    while (!myStack.empty()) {
        sum += myStack.top();
        myStack.pop();
    }
    printf("Sum:%d\n", sum);
    if (myStack.empty()) {
        printf("MyStack Is Empty!\n");
    }
    return 0;
}