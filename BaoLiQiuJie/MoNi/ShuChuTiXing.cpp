#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int h, k = 0;
    scanf("%d", &h);
    for (int i = h; i < h+h; i++) {
        for (int j = 0; j < i; j++) {
            printf("*");
        }

        printf("\n");
    }
    return 0;
}
