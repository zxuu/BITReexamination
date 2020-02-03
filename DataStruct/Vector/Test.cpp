#include <iostream>
#include <cstdio>
#include <vector>


using namespace std;

vector<int> myVector;

int main(){
    for (int i = 0; i < 5; ++i) {
        myVector.push_back(i);
    }
    myVector.insert(myVector.begin(), 3, 15);
    myVector.pop_back();
    for (int j = 0; j < myVector.size(); ++j) {
        printf("%d ", myVector[j]);
    }
    printf("\n");
    printf("size:%d\n", myVector.size());
    myVector.erase(myVector.begin() + 5, myVector.end());
    vector<int>::iterator it;   //定义迭代器
    for (it = myVector.begin(); it != myVector.end(); it++) {
        printf("%d ", *it);
    }
    printf("\n");
    myVector.clear();
    return 0;
}