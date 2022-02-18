/*
 * 在str1中删除str2中的字母，对于str1中的每一个字母遍历str2，没有则往前覆盖，
 * 用K来标记str1中有多少和str2中没有的字母
 */
#include <stdio.h>
#include <string.h>

void main(){
    char s1[100], s2[100];
    int i, j = 0, k = 0, len;
    scanf("%s", s1);
    scanf("%s", s2);
    len = strlen(s2);
    for(i=0;s1[i]!='\0';i++){
        while (s1[i] != s2[j]) {
            j++;
        }
        if (j >= len) {
            s1[k]=s1[i];
            k++;
        }
        j = 0;
    }
    s1[k] = '\0';
    printf("%s\n", s1);
}