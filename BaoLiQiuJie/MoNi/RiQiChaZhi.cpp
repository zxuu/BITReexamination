#include <iostream>
#include <cstdio>

using namespace std;
int daytap[2][13] = {   //Ô¤´¦Àí
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
bool IsLeapYear(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int main(){
    int day1,day2;
    int temp;
    int year, month, day;
    scanf("%d%d", &day1, &day2);
    if (day1 > day2) {
        temp = day1;
        day1 = day2;
        day2 = temp;
    }

    return 0;
}

