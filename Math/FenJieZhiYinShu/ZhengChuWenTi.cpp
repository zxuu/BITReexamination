#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

long long JieCheng(int n){
    int m = 1;
    while (n > 0) {
        m *= n;
        n--;
    }
    return m;
}
int main(){
    int n,a;
    while (cin >> n >> a) {
        long long jieCh = JieCheng(n);
        printf("jieCh:%d\n", jieCh);
        int t = 0, k = 0;
        while (pow(a, t+1) <= jieCh) {
            if (jieCh % int(pow(a, t)) == 0
                && jieCh % int(pow(a, t + 1)) != 0) {
                k = t;
            }
            t++;
        }
        cout << k << endl;
    }
    return 0;
}