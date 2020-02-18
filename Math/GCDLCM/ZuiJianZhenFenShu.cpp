/*(最简真分数)
 *
 */

#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

int GCD(int a,int b){
    if (b==0)
        return a;
    else
        return GCD(b, a % b);
}

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;
        int a[n];
        for (int i = 0; i < n; ++i) {
            scanf("%d", &a[i]);
        }
        sort(a, a + n);
        int number = 0;
        for (int j = 0; j < n - 1; ++j) {
            for (int i = j + 1; i < n; ++i) {
                if (GCD(a[i],a[j]) == 1)
                    number++;
            }
        }
        printf("%d\n", number);
    }
    return 0;
}