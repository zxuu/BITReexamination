#include <stdio.h>
#include <string.h>

void swap(char **pa,char **pb){
    char *temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}
void main(){
    char a[] = "UESTC";
    char *b = "CST"; //指向字符串的指针？
//    swap(a, b);
    strcpy(a, "dd");
    puts(a);
    puts(b);
}