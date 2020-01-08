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
        scanf("%d%d%d", &a, &b, &c);
        if (a == 0) {
            printf("x=%.2f\n", (0.0 - c+0.0) / b);
        } else{
            if (b * b - 4 * a * c < 0) {
                printf("-1\n");
            } else if (b * b - 4 * a * c > 0) {
                printf("x1=%.2f,x2=%.2f\n", ((0 - b+0.0) - sqrt(b * b - 4 * a * c)) / 2.0 * a,
                       ((0 - b+0.0) + sqrt(b * b - 4 * a * c)) / 2.0 * a);
            } else {
                printf("x=%.2f\n", (0 - b+0.0) / 2.0 * a);
            }
        }
    }
}
