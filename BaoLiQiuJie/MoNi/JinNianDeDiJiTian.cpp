/*
��Ŀ����
�����ꡢ�¡��գ���������Ǳ���ĵڼ��졣
��������:
��������������(1<=Y<=3000)����(1<=M<=12)����(1<=D<=31)��
�������:
��������ж���������ݣ�����ÿһ��������ݣ�
���һ������������Input�е��ꡢ�¡��ն�Ӧ����ĵڼ��졣
ʾ��1
����
1990 9 20
2000 5 1
���
263
122
 */
#include <iostream>
#include <cstdio>

using namespace std;

int daytap[2][13] = {   //Ԥ����
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

