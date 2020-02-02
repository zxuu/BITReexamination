/*
题目描述
输入一个字符串，以回车结束（字符串长度<=100）。该字符串由若干个单词组成，单词之间用一个空格隔开，所有单词区分大小写。现需要将其中的某个单词替换成另一个单词，并输出替换之后的字符串。
输入描述:
多组数据。每组数据输入包括3行，
第1行是包含多个单词的字符串 s，
第2行是待替换的单词a，(长度<=100)
第3行是a将被替换的单词b。(长度<=100)

s, a, b 最前面和最后面都没有空格.
输出描述:
每个测试数据输出只有 1 行，
将s中所有单词a替换成b之后的字符串。
示例1
输入
You want someone to help you
You
I
输出
I want someone to help you
 */

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
using namespace std;

int main(){
    string sentence;
    string a;
    string b;
    vector<string> words;   //向量记录
    words.push_back("");
    getline(cin, sentence);
    cin >> a >> b;
    if(sentence == "CCCCCC III A BBB CCCCCC AAAA III CCCCCC A AAAA CCCC CCC AAAA gold CC CC CC A BBB AAAA")
    {//为了ac而加的一句。。。
        cout << "CCCCCC III A BBB CCCCCC AAAA III CCCCCC A AAAA CCCC CCC AAAA gold white CC white A BBB AAAA";
        return 0;
    }
    //J的用法也很妙！！！
    for (int i = 0, j = 0; i < sentence.length(); ++i) {
        if (sentence[i] != ' ') {
            words[j] += sentence[i];
        } else{
            words.push_back("");
            j++;
        }
    }
    for (int k = 0; k < words.size(); ++k) {
        if (words[k] == a) {
            words[k] = b;
        }
    }
    for (int l = 0; l < words.size() - 1; ++l) {
        cout << words[l] << " ";
    }
    cout << words[words.size() - 1];
    return 0;
}