/*(简单密码)
题目描述
Julius Caesar曾经使用过一种很简单的密码。 对于明文中的每个字符，将它用它字母表中后5位对应的字符来代替，这样就得到了密文。 比如字符A用F来代替。如下是密文和明文中字符的对应关系。 密文 A B C D E F G H I J K L M N O P Q R S T U V W X Y Z 明文 V W X Y Z A B C D E F G H I J K L M N O P Q R S T U 你的任务是对给定的密文进行解密得到明文。 你需要注意的是，密文中出现的字母都是大写字母。密文中也包括非字母的字符，对这些字符不用进行解码。
输入描述:
输入中的测试数据不超过100组。每组数据都有如下的形式，而且各组测试数据之间没有空白的行。
一组测试数据包括三部分：
1.    起始行 - 一行，包括字符串 "START"
2.    密文 - 一行，给出密文，密文不为空，而且其中的字符数不超过200
3.    结束行 - 一行，包括字符串 "END"
在最后一组测试数据之后有一行，包括字符串 "ENDOFINPUT"。
输出描述:
对每组数据，都有一行输出，给出密文对应的明文。
示例1
输入
START
NS BFW, JAJSYX TK NRUTWYFSHJ FWJ YMJ WJXZQY TK YWNANFQ HFZXJX
END
START
N BTZQI WFYMJW GJ KNWXY NS F QNYYQJ NGJWNFS ANQQFLJ YMFS XJHTSI NS WTRJ
END
START
IFSLJW PSTBX KZQQ BJQQ YMFY HFJXFW NX RTWJ IFSLJWTZX YMFS MJ
END
ENDOFINPUT
输出
IN WAR, EVENTS OF IMPORTANCE ARE THE RESULT OF TRIVIAL CAUSES
I WOULD RATHER BE FIRST IN A LITTLE IBERIAN VILLAGE THAN SECOND IN ROME
DANGER KNOWS FULL WELL THAT CAESAR IS MORE DANGEROUS THAN HE
 */

#include <iostream>
#include <string>
#include <cstdio>

using namespace std;
int main(){
    string str;
    while (getline(cin, str)) {
        if (str == "ENDOFINPUT") {
            break;
        }
        getline(cin, str);
        for (int i = 0; i < str.size(); ++i) {
            if ('A' <= str[i] && str[i] <= 'Z') {
                str[i] = (str[i] - 'A' - 5 + 26) % 26 + 'A';
            }
        }
        cout << str << endl;
        getline(cin, str);
        return 0;
    }
}