/*
 * 字符串SRC逆序输出
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main(){
    char *src = "hello,world";
    char *dest, *d, *p;
    int len, i;
    len = strlen(src);
    dest = (char *) malloc(sizeof(char) * (len + 1));
    p = &src[len - 1];
    d = dest;
    while (len-- != 0) {
        *d++ = *p--;
    }
    *d = '\0';
    printf("%s", dest);
}

