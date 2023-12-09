//
// Created by zxuu on 2020/1/8.
//
#include <stdio.h>

int main(){
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int m,k;
        scanf("%d", &m);
        char s[m][20];
        for (int j = 0; j < m; j++) {
            scanf("%c", &s[j]);
        }
        scanf("%d", &k);
        for (int l = 0; l < 20; l++) {
            printf("%c", s[l]);
        }
    }
}
