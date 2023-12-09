//
// Created by zxuu on 2020/1/8.
//
#include <stdio.h>
#include <math.h>
int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int a,b,c;
        float temp;
        scanf("%d%d%d", &a, &b, &c);
        temp=b*b-4*a*c;
        if (a == 0) {
            printf("x=%.2f\n", -c*1.0/b);
        } else{
            if (temp < 0) {
                printf("-1\n");
            } else if (temp > 0) {
                float x1,x2;
                x1=(-1*b*1.0-sqrt(temp))/(2*a);
                x2=(-1*b*1.0+sqrt(temp))/(2*a);
                printf("x1=%.2f,x2=%.2f\n",x1,x2);
            } else {
                float x;
                x=-1*b*1.0/(2*a);
                printf("x=%.2f\n",x);
            }
        }
    }
}
