/*(浮点数加法)
题目描述
求2个浮点数相加的和 题目中输入输出中出现浮点数都有如下的形式： P1P2...Pi.Q1Q2...Qj 对于整数部分，P1P2...Pi是一个非负整数 对于小数部分，Qj不等于0
输入描述:
对于每组案例，每组测试数据占2行，分别是两个加数。
输出描述:
每组案例是n行，每组测试数据有一行输出是相应的和。
输出保证一定是一个小数部分不为0的浮点数
示例1
输入
0.111111111111111111111111111111
0.111111111111111111111111111111
输出
0.222222222222222222222222222222
 */



#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

string add(string sa, string sb){
    string result, sc, sd;
    /******************将两浮点数对齐**********************************/
    /*************下面是将两浮点数对齐***********/
    int ia = sa.find(".", 0);
    int ib = sb.find(".", 0);
    sc = (ia>ib)?sa:sb;
    sd = (ia>ib)?sb:sa;
    int n = (ia>ib)?(ia-ib):(ib-ia);
    while(n--)
    {
        sd = "0"+sd;
    }
    int lenc = sc.length();
    int lend = sd.length();
    sa = (lenc>lend)?sc:sd;
    sb = (lenc>lend)?sd:sc;
    n = (lenc>lend)?(lenc-lend):(lend-lenc);
    while(n--)
    {
        sb+="0";
    }
    /********下面是对对齐后的浮点数进行相加********/
    int carry = 0;
    for(int i = sa.length()-1; i>=0; i--)
    {
        if(sa[i]=='.')
        {
            result = "."+result;
            continue;
        }
        int value = sa[i]-'0'+sb[i]-'0'+carry;
        result = char(value%10+'0')+result;
        carry = value/10;
    }
    while(carry!=0)
    {
        result = char(carry%10+'0')+result;
        carry/=10;
    }
    return result;
}
int main(){
    string a, b;
    while (cin >> a >> b) {
        cout << add(a, b) << endl;
    }
    return 0;
}