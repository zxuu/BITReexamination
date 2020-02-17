/*(十进制转化为八进制)
 *
 */

#include <iostream>
#include <cstdio>
#include <stack>
#include <vector>

using namespace std;

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        stack<int> eight;
        while (n != 0) {
            eight.push(n % 8);
            n /= 8;
        }
        while (!eight.empty()) {
            printf("%d", eight.top());
            eight.pop();
        }
        printf("\n");
    }
    return 0;
}