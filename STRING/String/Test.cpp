#include <string>

using namespace std;

int main(){
    string s = "hello,world";
    for (string::iterator it = s.begin(); it != s.end(); ++it) {
        printf("%c", *it);
    }
    printf("\n");
    return 0;
}