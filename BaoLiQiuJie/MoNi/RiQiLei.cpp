/*
题目描述
编写一个日期类，要求按xxxx-xx-xx 的格式输出日期，实现加一天的操作。
输入描述:
输入第一行表示测试用例的个数m，接下来m行每行有3个用空格隔开的整数，分别表示年月日。测试数据不会有闰年。
输出描述:
输出m行。按xxxx-xx-xx的格式输出，表示输入日期的后一天的日期。
示例1
输入
2
1999 10 20
2001 1 31
输出
1999-10-21
2001-02-01
备注:
注意个位数日期前面要有0。
 */
#include <iostream>
#include <cstdio>

using namespace std;

int daytag[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    int n;
    scanf("%d", &n);
    while (n--) {
        int year, month, day;
        scanf("%d%d%d", &year, &month, &day);
        if (day + 1 > daytag[month]) {
            if (month != 12) {
                printf("%d-%02d-%02d\n", year, month+1, 1);
            } else
                printf("%d-%02d-%02d\n", year + 1, 1, 1);
        } else
            printf("%d-%02d-%02d\n", year, month, day + 1);
    }
    return 0;
}