/*(畅通工程|小镇群连接)
题目描述
    某省调查城镇交通状况，得到现有城镇道路统计表，表中列出了每条道路直接连通的城镇。省政府“畅通工程”的目标是使全省任何两个城镇间都可以实现交通（但不一定有直接的道路相连，只要互相间接通过道路可达即可）。问最少还需要建设多少条道路？
输入描述:
    测试输入包含若干测试用例。每个测试用例的第1行给出两个正整数，分别是城镇数目N ( < 1000 )和道路数目M；随后的M行对应M条道路，每行给出一对正整数，分别是该条道路直接连通的两个城镇的编号。为简单起见，城镇从1到N编号。
    注意:两个城市之间可以有多条道路相通,也就是说
    3 3
    1 2
    1 2
    2 1
    这种输入也是合法的
    当N为0时，输入结束，该用例不被处理。
输出描述:
    对每个测试用例，在1行里输出最少还需要建设的道路数目。
示例1
输入
4 2
1 3
4 3
3 3
1 2
1 3
2 3
5 2
1 2
3 5
999 0
0
输出
1
0
2
998
 */


#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1000;

int father[MAXN];   //父亲节点
int height[MAXN];   //接点高度

void Initial(int n){    //初始化
    for (int i = 0; i <= n; ++i) {
        father[i] = i;//每个节点的父亲为自己
        height[i] = 0;//每个节点的高度为0
    }
}

int Find(int x){//寻找父节点
    if (x != father[x]) {//路径压缩|如果父节点不是自己
        father[x] = Find(father[x]);//父节点的父节点就是自己
    }
    return father[x];//返回父节点
}

void Union(int x,int y){//合并集合
    x = Find(x);
    y = Find(y);
    if (x != y) {   //矮树作为高树的子数
        if (height[x] < height[y]) {
            father[x] = y;
        } else if (height[y] < height[x]) {
            father[y] = x;
        } else{
            father[y] = x;
            height[x]++;
        }
    }
    return;
}

int main(){
    int n,m;
    while (scanf("%d", &n) != EOF) {
        if (n==0)
            break;
        scanf("%d", &m);
        Initial(n);
        while (m--) {
            int x,y;
            scanf("%d", &x);
            scanf("%d", &y);
            Union(x, y);
        }
        int answer = -1;
        for (int i = 1; i <= n; ++i) {
            if (Find(i) == i) {
                answer++;
            }
        }
        cout << answer << endl;
    }
    return 0;
}