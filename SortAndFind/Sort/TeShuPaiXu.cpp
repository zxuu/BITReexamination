#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n==1){
            int k;
            scanf("%d", &k);
            printf("%d\n", k);
            printf("-1\n");
        } else{
            int max = 0;
            int data[1001] = {0};
            for (int i = 0; i < n; ++i) {
                int k;
                scanf("%d", &k);
                if (k > max) {
                    max = k;
                }
                data[k]++;
            }
            printf("%d\n", max);
            for (int j = 0; j < 1001; ++j) {
                if (j == max)
                    data[j]--;
                for (int i = 0; i < data[j]; ++i) {
                    printf("%d ", j);
                }
            }
            printf("\n");
        }
    }
    return 0;
}