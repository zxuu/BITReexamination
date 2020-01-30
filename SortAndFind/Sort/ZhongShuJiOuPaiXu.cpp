#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main(){
    int a[10] = {0};
    int b[10] = {0};
    while (cin>>a[0]>>a[1]>>a[2]>>a[3]>>a[4]>>a[5]>>a[6]>>a[7]>>a[8]>>a[9]) {
        int p = 0, q = 9;
        sort(a, a + 10);
        for (int i = 9; i > -1; i--) {
            if (a[i]%2 != 0){
                b[p] = a[i];
                p++;
            } else {
                b[q] = a[i];
                q--;
            }
        }
        for (int j = 0; j < 10; ++j) {
            printf("%d ", b[j]);
        }
        printf("\n");
    }
    return 0;
}