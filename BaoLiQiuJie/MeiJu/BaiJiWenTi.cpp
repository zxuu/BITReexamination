/*
题目描述
    用小于等于n元去买100只鸡，大鸡5元/只，小鸡3元/只,还有1/3元每只的一种小鸡，分别记为x只,y只,z只。编程求解x,y,z所有可能解。
输入描述:
    测试数据有多组，输入n。
输出描述:
    对于每组输入,请输出x,y,z所有可行解，按照x，y，z依次增大的顺序输出。
示例1
输入
复制
40
输出
复制
x=0,y=0,z=100
x=0,y=1,z=99
x=0,y=2,z=98
x=1,y=0,z=99
 */
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        for (int x = 0; x <=20 ; x++) {
            for (int y = 0; y <=34 ; y++) {
                for (int z = 0; z <=300 ; z++) {
                    if ((x+y+z==100) && (x*5+y*3+z/3.0<=n))
                        printf("x=%d,y=%d,z=%d\n", x, y, z);
                }
            }
        }
    }

    return 0;
}

