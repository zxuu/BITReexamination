/*
题目描述
We now use the Gregorian style of dating in Russia. The leap years are years with number divisible by 4 but not divisible by 100, or divisible by 400. For example, years 2004, 2180 and 2400 are leap. Years 2004, 2181 and 2300 are not leap. Your task is to write a program which will compute the day of week corresponding to a given date in the nearest past or in the future using today’s agreement about dating.
输入描述:
There is one single line contains the day number d, month name M and year number y(1000≤y≤3000). The month name is the corresponding English name starting from the capital letter.
输出描述:
Output a single line with the English name of the day of week corresponding to the date, starting from the capital letter. All other letters must be in lower case.

Month and Week name in Input/Output:
January, February, March, April, May, June, July, August, September, October, November, December
Sunday, Monday, Tuesday, Wednesday, Thursday, Friday, Saturday
示例1
输入
9 October 2001
14 October 2001

输出
Tuesday
Sunday
 */
#include <iostream>
#include <cstdio>

using namespace std;
int daytag[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};

bool IsLeapYear(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
string months[13] ={"Haha","January","February","March","April","May","June","July","August","September","October"
             ,"November","December"};
string weeks[8]={"","Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int main(){
    int number, weekInt, monthInt;
    int year,day;
    string monthStr;
    while (cin >> day >> monthStr >> year) {
        number = 0;
        for (int i = 0; i < 13; ++i) {
            if (monthStr == months[i]) {
                monthInt = i;
                break;
            }
        }
        int row = IsLeapYear(year);
        for (int j = 0; j < monthInt; ++j) {
            number += daytag[row][j];
        }
        number += day;
        weekInt = number % 7 + 1;
        cout << weeks[weekInt] << endl;
    }
    return 0;
}
