#define PI 'A'
#include <stdio.h>
/*
求两个数最大值
int main(){
    int max(int x,int y);   //声明函数
    int a,b,c;
    scanf("%d,%d", &a, &b);
    c = max(a, b);
    printf("max=%d\n", c);
    return 0;
}

int max(int x,int y){
    return x > y ? x : y;
}
*/

/*
 * 大写字母转换为小写字母


void main(){
    printf("%c\n", PI + 32);
    printf("%d\n", PI + 32);
}
 */
int func(int *p){
    return (*p-- = 3) - 1;  //返回的是3-1
}
void main(){
    int arr[] = {10,7, 5};
    int *p = arr + 1;
    printf("%d", func(p) + *p);
}
