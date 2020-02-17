/*(十进制转二进制、二进制转十进制，数字为字符串)
题目描述
    对于一个十进制数A，将A转换为二进制数，然后按位逆序排列，再转换为十进制数B，我们称B为A的二进制逆序数。     例如对于十进制数173，它的二进制形式为10101101，逆序排列得到10110101，其十进制数为181，181即为173的二进制逆序数。
输入描述:
    一个1000位(即10^999)以内的十进制数。
输出描述:
    输入的十进制数的二进制逆序数。
示例1
输入
173
输出
181
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

//字符串除法
string Divide(string str,int x){
    int remainder = 0;
    for (int i = 0; i < str.size(); ++i) {
        int current = remainder * 10 + str[i] - '0';
        str[i] = current / x + '0';
        remainder = current % x;
    }
    int pos = 0;
    while (str[pos] == '0') {//  寻找首个非零下标
        pos++;
    }
    return str.substr(pos); //  删除前置多余的零
}
//字符串乘法
string Multiple(string str,int x){
    int carry = 0;  //保存进位
    for (int i = str.size()-1; i >= 0 ; --i) {
        int currnt = x * (str[i] - '0') + carry;
        str[i] = currnt % 10 + '0';
        carry = currnt / 10;
    }
    if (carry!=0) { //如果容有进位
        str = "1" + str;
    }
    return str;
}

string add(string str,int x){   //字符串加法
    int carry = x;
    for (int i = str.size()-1; i >=0 ; --i) {
        int current = (str[i] - '0') + carry;
        str[i] = current % 10 + '0';
        carry = current / 10;
    }
    if (carry!=0) { //荣有进位
        str = "1" + str;
    }
    return str;
}

int main(){
    string str;
    while (cin >> str) {
        vector<int> binary;
        while (str.size() != 0) {
            int last = str[str.size() - 1] - '0';   //最低位的值
            binary.push_back(last % 2);    //取模运算
            str = Divide(str, 2);    //整除运算（str/2）
        }
        string answer = "0";
        for (int i = 0; i < binary.size(); ++i) {
            answer = Multiple(answer, 2);    //乘法运算
            answer = add(answer, binary[i]);
        }
        cout << answer << endl;
    }
    return 0;
}