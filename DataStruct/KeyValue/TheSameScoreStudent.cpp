/*(统计同成绩学生人数)
题目描述
读入N名学生的成绩，将获得某一给定分数的学生人数输出。
输入描述:
测试输入包含若干测试用例，每个测试用例的格式为


第1行：N
第2行：N名学生的成绩，相邻两数字用一个空格间隔。
第3行：给定分数

当读到N=0时输入结束。其中N不超过1000，成绩分数为（包含）0到100之间的一个整数。
输出描述:
对每个测试用例，将获得给定分数的学生人数输出。
示例1
输入
3
80 60 90
60
2
85 66
0
5
60 75 90 55 75
75
0
输出
1
0
2
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

//标记数组
//int main(){
//    int n;
//    while (cin >> n) {
//        if (n==0)
//            break;
//        int a[1001] = {0};
//        for (int i = 0; i < n; ++i) {
//            int k;
//            scanf("%d", &k);
//            a[k]++;
//        }
//        int score;
//        scanf("%d", &score);
//        printf("%d\n", a[score]);
//    }
//    return 0;
//}

int main(){
    int n;
    while (cin >> n) {
        if (n==0)
            break;
        map<int,int> myMap;
        for (int i = 0; i < n; ++i) {
            int k;
            cin >> k;
            myMap[k]++;
        }
        int goal;
        cin >> goal;
        map<int, int>::iterator it = myMap.find(goal);
//        myMap.find(goal)->second;
        cout << myMap.find(goal)->second << endl;
    }
    return 0;
}