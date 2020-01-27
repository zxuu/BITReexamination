/*
��Ŀ����(��ӡ����)
�������m��һ���еĵ�n�죬�����n���Ǽ��¼��š�
��������:
���������������y(1<=y<=3000)��n(1<=n<=366)��
�������:
�����ж���������ݣ�����ÿ�����ݣ�
�� yyyy-mm-dd�ĸ�ʽ�������ж�Ӧ�����ڴ�ӡ������
ʾ��1
����
2000 3
2000 31
2000 40
2000 60
2000 61
2001 60
���
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
    int year, month, day, number;   //number��¼����
    while (scanf("%d%d", &year, &number) != EOF) {
        month = 0;  //��ʼ����
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

