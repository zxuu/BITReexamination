//
// Created by zxuu on 2020/1/11.
//
#include <stdio.h>
#include <string.h>
int main(){
    int n;
    char s[50];
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++) {
        gets(s);
        for (int k = 0; k < strlen(s); k++) {
            if ('0'<=s[k]&&s[k]<='9'){
                printf("%d ", k+1);
            }
        }
        printf("\n");
    }
}
