/*
猫狗收容所
 */

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct animal{
    int number;
    int order;
    animal(int n,int o): number(n),order(o){    //构造函数

    }
};

int main(){
    queue<animal> cats;
    queue<animal> dogs;
    int n;
    int order = 0;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int method, type;
        scanf("%d%d", &method, &type);
        if (method == 1) {
            if (type > 1) {
                dogs.push(animal(type, order++));
            } else
                cats.push(animal(type, order++));
        } else{
            if (type == 0 && !dogs.empty() && !cats.empty()) {
                if (dogs.front().order < cats.front().order) {
                    printf("%d ", dogs.front().number);
                    dogs.pop();
                } else{
                    printf("%d ", cats.front().number);
                    cats.pop();
                }
            } else if (type == 0 && dogs.empty() && !cats.empty()) {
                printf("%d ", cats.front().number);
                cats.pop();
            } else if (type == 0 && !dogs.empty() && cats.empty()) {
                printf("%d ", dogs.front().number);
                dogs.pop();
            } else if (type == 1 && !dogs.empty()) {
                printf("%d ", dogs.front().number);
                dogs.pop();
            } else if (type == -1 && !cats.empty()) {
                printf("%d ", cats.front().number);
                cats.pop();
            }
        }
    }
    printf("\n");
    return 0;
}