
/*
 * 值传递
 */

#include <stdio.h>
void swap(int a[],int b[]){
    a[1] = 5;
    b[1] = 6;
}

int  main(){
    int a[] = {1, 2};
    int b[] = {3, 4};
    swap(a, b);
    printf("%d %d", a[1], b[1]);
    return 0;
}