//
// 输入一个字符串，将连续相同的字符串删减为一个，以“*”为结尾
//
#include <stdio.h>
void main(){
    char c_old, c_new;
    c_old = '*';
    do {
        scanf("%c", &c_new);    //一定戴&
        if (c_new == c_old) {
            continue;
        }
        c_old = c_new;
        printf("%c", c_old);
    } while (c_new != '*');
}

