/*
题目描述(中序和前序确定二叉树)
二叉树的前序、中序、后序遍历的定义： 前序遍历：对任一子树，先访问跟，然后遍历其左子树，最后遍历其右子树； 中序遍历：对任一子树，先遍历其左子树，然后访问根，最后遍历其右子树； 后序遍历：对任一子树，先遍历其左子树，然后遍历其右子树，最后访问根。 给定一棵二叉树的前序遍历和中序遍历，求其后序遍历（提示：给定前序遍历与中序遍历能够唯一确定后序遍历）。
输入描述:
两个字符串，其长度n均小于等于26。
第一行为前序遍历，第二行为中序遍历。
二叉树中的结点名称以大写字母表示：A，B，C....最多26个结点。
输出描述:
输入样例可能有多组，对于每组测试样例，
输出一行，为后序遍历的字符串。
示例1
输入
ABC
BAC
FDXEAG
XDEFAG
输出
BCA
XEDGAF
 */

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct TreeNode{
    char c;
    TreeNode *leftChild;
    TreeNode *rightChild;
    TreeNode(char c):
        c(c),leftChild(NULL),rightChild(NULL){}
};

TreeNode* Build(string str1,string str2){
    if (str1.size() == 0)
        return NULL;
    char c = str1[0];
    TreeNode *root = new TreeNode(c);
    int position = str2.find(c);
    root->leftChild = Build(str1.substr(1, position), str2.substr(0, position));
    root->rightChild = Build(str1.substr(position + 1), str2.substr(position + 1));
    return root;
}

void PostOrder(TreeNode* root){
    if (root == NULL) {
        return;
    }
    PostOrder(root->leftChild);
    PostOrder((root->rightChild));
    printf("%c", root->c);
}

int main(){
    string str1, str2;
    while (cin >> str1 >> str2) {
        TreeNode *root = Build(str1, str2);
        PostOrder(root);
        printf("\n");
    }
    return 0;
}