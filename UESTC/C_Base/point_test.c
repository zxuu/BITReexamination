//交换两字符串
#include <stdio.h>

void swap(char **p,char **q){
    char  *temp;
    temp = *p;
    *p=*q;
    *q=temp;
}

void main(){

    char *a = "aaa";
    char *b = "bbb";
    swap(&a, &b);
//    printf("%s\n", a);
//    printf("%s\n", b);
    puts(a);
    puts(b);
}