//
// 将字符串SRC逆序输出
//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void main(){
    char *src = "hello,world";
    char *dest, *d, *p;
    int len, i;
    len = strlen(src);  //字符串SRC的长度
    dest = (char *) malloc(len);
    p = &src[len - 1];
    d = dest;
    while (len-- != 0) {
        *d++ = *p--;
    }
    printf("%s\n", dest);
}
