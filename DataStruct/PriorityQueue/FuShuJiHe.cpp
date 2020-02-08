/*(复数集合)
题目描述
    一个复数（x+iy）集合，两种操作作用在该集合上：
    1、Pop 表示读出集合中复数模值最大的那个复数，如集合为空 输出  empty  ，不为空就输出最大的那个复数并且从集合中删除那个复数，再输出集合的大小SIZE；
    2 Insert a+ib  指令（a，b表示实部和虚部），将a+ib加入到集合中 ，输出集合的大小SIZE；     最开始要读入一个int n，表示接下来的n行每一行都是一条命令。
输入描述:
输入有多组数据。
每组输入一个n(1<=n<=1000)，然后再输入n条指令。
输出描述:
根据指令输出结果。

模相等的输出b较小的复数。
a和b都是非负数。


示例1
输入
3
Pop
Insert 1+i2
Pop
输出
empty
SIZE = 1
1+i2
SIZE = 0
 */

#include <iostream>
#include <cstdio>
#include <queue>
#include <string>

using namespace std;

struct Complex {
    int real;
    int imag;
    Complex(int a,int b):
        real(a),imag(b){}
    //重载小于号<
    bool operator< (Complex c) const {
        return real * real + imag * imag < c.real * c.real + c.imag * c.imag;
    }
};

int main(){
    int n;
    while (cin >> n) {
        priority_queue<Complex> myPriorityQueue;
        while (n--) {
            string str;
            cin >> str;
            if (str == "Pop") {
                if (myPriorityQueue.empty()) {
                    printf("empty\n");
                } else{
                    Complex current = myPriorityQueue.top();
                    myPriorityQueue.pop();
                    printf("%d+i%d\n", current.real, current.imag);
                    printf("SIZE = %d\n", myPriorityQueue.size());
                }
            } else {
                int a, b;
                scanf("%d+i%d", &a, &b);
                myPriorityQueue.push(Complex(a, b));
                printf("SIZE = %d\n", myPriorityQueue.size());
            }
        }
    }
    return 0;
}