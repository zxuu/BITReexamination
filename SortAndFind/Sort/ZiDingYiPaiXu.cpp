/*
题目描述(成绩排序|自定义排序)
用一维数组存储学号和成绩，然后，按成绩排序输出。
输入描述:
输入第一行包括一个整数N(1<=N<=100)，代表学生的个数。
接下来的N行每行包括两个整数p和q，分别代表每个学生的学号和成绩。
输出描述:
按照学生的成绩从小到大进行排序，并将排序后的学生信息打印出来。
如果学生的成绩相同，则按照学号的大小进行从小到大排序。
示例1
输入
3
1 90
2 87
3 92
输出
2 87
1 90
3 92
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct Student{
    int number;
    int score;
};

const int MAXN = 100;

Student arr[MAXN];

bool Compare(Student x,Student y){
    if (x.score != y.score) {
        return x.score < y.score;
    } else
        return x.number < y.number;
}
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &arr[i].number, &arr[i].score);
    }
    sort(arr, arr + n, Compare); //自定义排序
    for (int j = 0; j < n; ++j) {
        printf("%d %d\n", arr[j].number, arr[j].score);
    }
    return 0;
}