#include <stdio.h>

int main() {
    int fac(int n);
    int i;
    for (int i = 1; i < 5; i++) {
        printf("%d! = %d\n", i, fac(i));
    }
    return 0;
}

int fac(int n){
    static int f = 1;  //��̬������ֵÿ����һ�ξͻ�ı�
    f = f * n;
    return f;
}
