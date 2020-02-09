/*
 *散列表的应用
 */

#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

map<string, int> myMap;

int main(){
    //添加元素
    myMap["Emma"] = 67;
    myMap["Benedict"] = 100;
    myMap.insert(pair<string, int>("Bob", 72));
    myMap.insert(pair<string, int>("Mary", 85));
    myMap.insert(pair<string, int>("Alice", 93));
    cout << "SIZE:" << myMap.size() << endl;
    //查找元素
    cout << "the score of Benedict" << myMap["Benedict"];
    cout << "the score of Mary" << myMap.at("Mary");
    //删除元素
    myMap.erase("Benedict");
    cout << "SIZE:" << myMap.size() << endl;
    //定义迭代器
    map<string, int>::iterator it;
    for (it = myMap.begin(); it != myMap.end(); it++) {
        cout << "the score of " << it->first;
        cout << ":" << it->second << endl;
    }
    //清空元素
    myMap.clear();
    cout << "SIZE after clear:" << myMap.size() << endl;
    return 0;
}