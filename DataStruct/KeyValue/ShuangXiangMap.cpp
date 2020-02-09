/*()哈利波特与魔法||双向映射
题目描述
    哈利波特在魔法学校的必修课之一就是学习魔咒。据说魔法世界有100000种不同的魔咒，哈利很难全部记住，但是为了对抗强敌，他必须在危急时刻能够调用任何一个需要的魔咒，所以他需要你的帮助。     给你一部魔咒词典。当哈利听到一个魔咒时，你的程序必须告诉他那个魔咒的功能；当哈利需要某个功能但不知道该用什么魔咒时，你的程序要替他找到相应的魔咒。如果他要的魔咒不在词典中，就输出“what?”
输入描述:
    首先列出词典中不超过100000条不同的魔咒词条，每条格式为：

    [魔咒] 对应功能

    其中“魔咒”和“对应功能”分别为长度不超过20和80的字符串，字符串中保证不包含字符“[”和“]”，且“]”和后面的字符串之间有且仅有一个空格。词典最后一行以“@END@”结束，这一行不属于词典中的词条。
    词典之后的一行包含正整数N（<=1000），随后是N个测试用例。每个测试用例占一行，或者给出“[魔咒]”，或者给出“对应功能”。
输出描述:
    每个测试用例的输出占一行，输出魔咒对应的功能，或者功能对应的魔咒。如果魔咒不在词典中，就输出“what?”
示例1
输入
[expelliarmus] the disarming charm
[rictusempra] send a jet of silver light to hit the enemy
[tarantallegra] control the movement of one's legs
[serpensortia] shoot a snake out of the end of one's wand
[lumos] light the wand
[obliviate] the memory charm
[expecto patronum] send a Patronus to the dementors
[accio] the summoning charm
@END@
4
[lumos]
the summoning charm
[arha]
take me to the sky
输出
light the wand
accio
what?
what?
 */

#include <iostream>
#include <cstdio>
#include <string>
#include <map>

using namespace std;

map<string, string> dictionary;

int main(){
    string str;
    while (getline(cin, str)) {
        if (str == "@END@")
            break;
        int pos = str.find("]");    //分界点
        string key = str.substr(0, pos + 1);    //魔咒
        string value = str.substr(pos + 2);     //功能
        dictionary[key] = value;
        dictionary[value] = key;
    }
    int n;
    scanf("%d", &n);
    //吃掉回车
    getchar();  //吃掉回车
    while (n--) {
        string key;
        getline(cin, key);
        string answer = dictionary[key];
        if (answer == "") {
            answer = "what?";
        } else if (answer[0] == '[') {  //  魔咒需要删除方括号
            answer = answer.substr(1, answer.size() - 2);
        }
        cout << answer << endl;
    }
    return 0;
}