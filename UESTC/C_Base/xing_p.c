#include <stdio.h>

void main(){
//    int i;
//    char s[5], *p;
//    for (i = 0; i < 5; i++) {
//        s[i] = getchar();
//    }
//    s[i] = '\0';
//    p = s;
//    i = 0;
//    while (p != '\0') {
//        putchar(p[i++]);  //*p++
//    }
    int a[3] = {1, 2, 3};
    for (int i = 0; i < 3; ++i) {
        printf("%5d", a[i]);
    }
}