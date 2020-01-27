/*
题目描述(打印日期)
给出年分m和一年中的第n天，算出第n天是几月几号。
输入描述:
输入包括两个整数y(1<=y<=3000)，n(1<=n<=366)。
输出描述:
可能有多组测试数据，对于每组数据，
按 yyyy-mm-dd的格式将输入中对应的日期打印出来。
示例1
输入
2000 3
2000 31
2000 40
2000 60
2000 61
2001 60
输出
2000-01-03
2000-01-31
2000-02-09
2000-02-29
2000-03-01
2001-03-01
 */
#include <iostream>
#include <cstdio>

using namespace std;

int daytap[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

bool IsLeapYear(int year){
    return (year == 0 && year % 100 != 0) || (year % 400 == 0);
}
int main(){
    int year, month, day, number;   //number记录天数
    while (scanf("%d%d", &year, &number) != EOF) {
        month = 0;  //初始化月
        int row = IsLeapYear(year);
        while (number > daytap[row][month]) {
            number -= daytap[row][month];
            month++;
        }
        day = number;
        printf("%04d-%02d-%02d\n", year, month, day);
    }
    return 0;
}

