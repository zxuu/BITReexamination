/*(最小公倍数)
 *
 */

#include <iostream>
#include <cstdio>

using namespace std;

int GCD(int a,int b){   //最大公约数
    if (b==0) {
        return a;
    } else
        return GCD(b, a % b);
}

int main(){
    int a, b;
    while (scanf("%d%d", &a, &b) != EOF) {
        printf("%d\n", a * b / GCD(a, b));
    }
    return 0;
}