#include<stdio.h>
#include<stdlib.h>


int main(){
    char a[5];
    for (int i = 0; i < 50; i++) {
        itoa(i * i, a, 10);
        printf("%d ", sizeof(a));
    }
}

