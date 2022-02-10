//
// Created by z1825 on 2-10 0010.
//将str2插入到str1，从第m+1个位置开始，str1原本的字符往后移
//
#include <stdio.h>
void func(char *str1, char *str2,int m){
    int len1=0,len2=0;
    int i=0,k=0;
    while(str1[i]!='\0'){
        ++i;
        ++len1;
    }
    i=0;
    while (str2[i]!='\0'){
        ++i;
        ++len2;
    }
    for(int j=0;j<len2;++j){
        for(i=len1+j;i>=m;--i){     //从第M个位置开始str1字符往后移
            str1[i+1]=str1[i];
        }
        str1[m] = str2[k];
        ++m;
        ++k;
    }
    str1[len1 + len2] = '\0';
}
int main(){
    char s1[50] = "hello_world";
    char s2[20] = "plato";
    int m;
    scanf("%d", &m);
    func(s1, s2, m);
    printf("%s\n", s1);
    return 0;
}


