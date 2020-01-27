#include <iostream>
#include <cstdio>

using namespace std;

int daytap[2][13] = {   //‘§¥¶¿Ì
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
};
bool IsLeapYear(int year){
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
int main(){
    int year, month, day;
    while (scanf("%d%d%d", &year, &month, &day) != EOF) {
        int number = 0;
        int row = IsLeapYear(year);
        for (int i = 0; i < month; ++i) {
            number += daytap[row][i];
        }
        number += day;
        printf("%d\n", number);
    }
    return 0;
}

