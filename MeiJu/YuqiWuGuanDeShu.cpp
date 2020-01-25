#include <iostream>
#include <cstdio>

using namespace std;
int func(int x){
    int single = 0;
    if (x % 7 == 0)
        return 1;
    while (x) {
        single = x % 10;
        if (single==7)
            return 1;
        x /= 10;
    }
    return 0;
}
int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        int sum = 0;
        for (int i = 1; i <= n; i++) {
            if (!func(i))
                sum += i * i;
        }
        printf("%d\n", sum);
    }


}