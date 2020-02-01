/*
题目描述
第一行输入一个数n，1 <= n <= 1000，下面输入n行数据，每一行有两个数，分别是x y。输出一组x y，该组数据是所有数据中x最小，且在x相等的情况下y最小的。
输入描述:
输入有多组数据。
每组输入n，然后输入n个整数对。
输出描述:
输出最小的整数对。
示例1
输入
5
3 3
2 2
5 5
2 1
3 6
输出
2 1
 */
#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

struct dataNode{
    int x;
    int y;
};

bool Compare(dataNode x,dataNode y){
    if (x.x != y.x) {
        return x.x < y.x;
    } else
        return x.y < y.y;
}
int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        dataNode arr[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &arr[i].x, &arr[i].y);
        }
        sort(arr, arr + n, Compare);
        printf("%d %d\n", arr[0].x, arr[0].y);
    }
    return 0;
}

/*

#include <stdio.h>
#define INT_MAX 0x7fffffff //此代表最大的整形数int
struct s{
    int x,y;
};
int main(){
    int n;
    while(~scanf("%d",&n)){
        struct s min,t;
        min.x=INT_MAX,min.y=INT_MAX;
        while(n--){
            scanf("%d %d",&t.x,&t.y);
            if(t.x<min.x || (t.x == min.x&&t.y < min.y))
                min = t;
        }
        printf("%d %d\n",min.x,min.y);
    }
}

 */