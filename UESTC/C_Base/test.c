#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char **pa,char **pb){
    char *temp;
    temp = *pa;
    *pa = *pb;
    *pb = temp;
}
void func(int n, int arr[]){
    int *p;
    int i=0;
    while (i++ < n){
        p = &arr[i];
        printf("%d,", *p);
        i++;
    }
    (*p) = 0;
}
void func2(char str[],char string[],int m,int n){
    int t=0,i;
    for (i = m - 1; i <= n;) {
        string[t++] = str[i++];
    }
}
void main(){
//    int arr[4] = {1, 2, 3, 4};
//    int i;
//    func(4, arr);
//    for (int j = 0; j < 4; j++) {
//        printf("%d,", arr[j]);
//    }
//    int m;
//    char str[100], string[100];
//    gets(str);  //获得字符串
//    int n = strlen(str);
//    scanf("%d", &m);
//    func2(str, string, m, n);
//    puts(string);   //输出字符串
        //分解质因数
    int a[3]={1,2,3};
    int *p=a;
    p++;
    printf("%d\n", *p);
    printf("%d\n", *p--);
    printf("%d\n", *p);

}