/*(寻找直系亲属| 找父节点)
题目描述
    如果A，B是C的父母亲，则A，B是C的parent，C是A，B的child，如果A，B是C的（外）祖父，祖母，则A，B是C的grandparent，C是A，B的grandchild，如果A，B是C的（外）曾祖父，曾祖母，则A，B是C的great-grandparent，C是A，B的great-grandchild，之后再多一辈，则在关系上加一个great-。
输入描述:
    输入包含多组测试用例,每组用例首先包含2个整数n（0<=n<=26）和m（0<m<50）, 分别表示有n个亲属关系和m个问题, 然后接下来是n行的形式如ABC的字符串，表示A的父母亲分别是B和C，如果A的父母亲信息不全，则用-代替，例如A-C,再然后是m行形式如FA的字符串,表示询问F和A的关系。

输出描述:
    如果询问的2个人是直系亲属，请按题目描述输出2者的关系，如果没有直系关系，请输出-。
    具体含义和输出格式参见样例.
示例1
输入
3 2
ABC
CDE
EFG
FA
BE
输出
great-grandparent
-
 */

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

const int MAXN = 27;

int child[MAXN];

int main(){
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF) {
        for (int i = 0; i < n; ++i) {
            char a,b,c;
            cin >> a >> b >> c;
            child[b-'A']=a-'A';
            child[c-'A']=a-'A';
        }
        for (int j = 0; j < m; ++j) {
            char p, c;

        }
    }
    return 0;
}