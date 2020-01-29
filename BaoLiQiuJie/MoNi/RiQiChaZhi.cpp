/*
题目描述
有两个日期，求两个日期之间的天数，如果两个日期是连续的我们规定他们之间的天数为两天
输入描述:
有多组数据，每组数据有两行，分别表示两个日期，形式为YYYYMMDD
输出描述:
每组数据输出一行，即日期差值
示例1
输入
20110412
20110422
输出
11
 */
#include <iostream>
#include <cstdio>

using namespace std;
int daytap[2][13] = {   //预处理
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
bool IsLeapYear(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

int Days(int year, int month, int day){
    int sumDays = 0;
    int row = IsLeapYear(year);
    for (int i = 0; i < month; ++i) {
        sumDays += daytap[row][i];
    }
    return sumDays + day;
}
int sumDayOfYear(int year){
    if (IsLeapYear(year)) {
        return 366;
    } else
        return 365;
}
int main(){
    int data1,data2;
    while (scanf("%d%d", &data1, &data2) != EOF) {
        int temp;
        int year1, year2, month1, month2, day1, day2;
        if (data1 > data2) {
            temp = data1;
            data1 = data2;
            data2 = temp;
        }
        year1 = data1 / 10000; month1=data1%10000/100; day1=data1%100;
        year2 = data2 / 10000; month2=data2%10000/100; day2=data2%100;
        if (year1 == year2) {
            printf("%d\n", Days(year2, month2, day2) - Days(year1, month1, day1) + 1);
        } else{
            printf("%d\n", 1 + sumDayOfYear(year1) - Days(year1, month1, day1) + Days(year2, month2, day2));
        }
    }

    return 0;
}

//计算两个日期距离0000年0月1日的天数再求差
/*

#include <bits/stdc++.h>
using namespace std;
int mon[12]={0,31,59,90,120,151,181,212,243,273,304,334};//字典
int cal(int y,int m,int d)//给出年月日，计算距离0000年0月1日的天数和
{
    return y*365+y/4-y/100+y/400+mon[m-1]+d-1+(y/100!=0&&y/4==0||y/400==0&&m>2);
}
int main()
{
    int x[2],year,month,day;
    for(int k=0;k<2;k++)//循环两次读入两个日期
    {
        scanf("%4d%2d%2d",&year,&month,&day);
        x[k]=cal(year,month,day);
    }
    cout<<abs(x[0]-x[1])+1;
}

 */

