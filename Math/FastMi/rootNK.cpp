#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

int FastExponentiation(int a,int b){
    int result = 1;
    while (b != 0) {
        if (b % 2 == 1) {
            result *= a;
            result %= 10000;
        }
        b /= 2;
        a *= a;
        a %= 10000;
    }
    return result;
}

int Sum(int n,int k){
    vector<int> vector;
    int sum = 0;
    while (n != 0) {
        vector.push_back(n % k);
        n /= k;
    }
    for (int i = 0; i < vector.size(); ++i) {
        sum += vector[i];
    }
    return sum;
}

int Root(int l,int k){
    if (l < k) {
        return l;
    } else{
        return Root(Sum(l, k), k);
    }
}
int main(){
    int x;
    int y, k;
    while (cin>>x>>y>>k) {
        int l = FastExponentiation(x, y);
        cout << Root(l, k) << endl;
    }
    return 0;
}