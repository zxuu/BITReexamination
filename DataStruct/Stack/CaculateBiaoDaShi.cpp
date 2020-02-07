/*(计算表达式)
题目描述
对于一个不存在括号的表达式进行计算
输入描述:
存在多种数据，每组数据一行，表达式不存在空格
输出描述:
输出结果
示例1
输入
6/2+3+3*4
输出
18
 */


//方法很巧妙！虽然没有用到栈，但总过程很像栈
#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

int main(){
    double i1;
    while (scanf("%lf", &i1) != EOF) {
        double a[1000],t;
        a[0] = i1;
        char ch;
        int i=0;
        while (scanf("%c", &ch) != EOF && ch != '\n') {
            scanf("%lf", &t);
            if (ch == '/') {    //如果是乘除的话，直接计算将结果代替i的位置上
                a[i] /= t;
            } else if (ch == '*') {
                a[i] *= t;
            } else if (ch == '-') { //减就是负的加，乘以负一加入数组中
                a[++i] = -t;
            } else if (ch == '+') { //如果是加，则将数字加入数组中
                a[++i] = t;
            }
        }
        //最后数组从0到i的位置都是要加的数，全部加起来就得到结果
        double sum = 0;
        for (int j = 0; j <= i; ++j) {
            sum += a[j];
        }
        printf("%.0f\n", sum);
    }
    return 0;
}