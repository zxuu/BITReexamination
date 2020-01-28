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

string months[13] ={"","January","February","March","April","May","June","July","August","September","October"
             ,"November","December"};
string weeks[7]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
int main(){
    int weekInt, monthInt;
    int year,day;
    string monthStr;
    while (cin >> day >> monthStr >> year) {
        for (int i = 0; i < 13; ++i) {
            if (monthStr == months[i]) {
                monthInt = i;
                break;
            }
        }
        //注意在公式中有个与其他公式不同的地方：把一月和二月看成是上一年的十三月和十四月，例：如果是2004-1-10则换算成：2003-13-10来代入公式计算。
        //以公元元年为参考，公元元年1月1日为星期一
        if (1 == monthInt || 2 == monthInt) {
            monthInt += 12;
            year--;
        }
        //基姆拉尔森计算公式:W= (d+1+2*m+3*(m+1)/5+y+y/4-y/100+y/400) mod 7
        weekInt = (day + 1 + 2 * monthInt + 3 * (monthInt + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
        cout << weeks[weekInt] << endl;
    }
    return 0;
}
