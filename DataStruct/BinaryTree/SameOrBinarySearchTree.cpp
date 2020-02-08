/*(排序二叉树是否为同一颗)
题目描述
判断两序列是否为同一二叉搜索树序列
输入描述:
开始一个数n，(1<=n<=20) 表示有n个需要判断，n= 0 的时候输入结束。
接下去一行是一个序列，序列长度小于10，包含(0~9)的数字，没有重复数字，根据这个序列可以构造出一颗二叉搜索树。
接下去的n行有n个序列，每个序列格式跟第一个序列一样，请判断这两个序列是否能组成同一颗二叉搜索树。
输出描述:
如果序列相同则输出YES，否则输出NO
示例1
输入
2
567432
543267
576342
0
输出
YES
NO
 */

//建树、比较
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct TreeNode {
    int data;
    TreeNode *leftChild;
    TreeNode *rightChild;
    TreeNode(int m):
        data(m),leftChild(NULL),rightChild(NULL){}
};

TreeNode* Insert(TreeNode* root,int x){ //建立二叉排序树
    if (root == NULL)
        root = new TreeNode(x);
    else if (x < root->data) {
        root->leftChild = Insert(root->leftChild, x);
    } else if (x > root->data) {
        root->rightChild = Insert(root->rightChild, x);
    }
    return root;
}

bool IsSame(TreeNode* root1,TreeNode* root2){       //递归判断两棵树是否相同
    if (root1 == NULL && root2 == NULL) {
        return true;
    } else if (root1 == NULL || root2 == NULL) {
        return false;
    } else{
        return IsSame(root1->leftChild, root2->leftChild) && IsSame(root1->rightChild, root2->rightChild);
    }
}

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        if (n == 0)
            break;
        TreeNode *root = NULL;
        string str;
        cin >> str;
        for (int i = 0; i < str.size(); ++i) {
            root = Insert(root, str[i] - '0');
        }
        for (int j = 0; j < n; ++j) {
            TreeNode *root2 = NULL;
            string str2;
            cin >> str2;
            for (int i = 0; i < str2.size(); ++i) {
                root2 = Insert(root2, str2[i] - '0');
            }
            printf("%s\n", IsSame(root, root2) ? "YES" : "NO");
        }

    }
    return 0;
}