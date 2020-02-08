/*(二叉排序树建立和前中后遍历,综合题)
题目描述
输入一系列整数，建立二叉排序树，并进行前序，中序，后序遍历。
输入描述:
输入第一行包括一个整数n(1<=n<=100)。
接下来的一行包括n个整数。
输出描述:
可能有多组测试数据，对于每组数据，将题目所给数据建立一个二叉排序树，并对二叉排序树进行前序、中序和后序遍历。
每种遍历结果输出一行。每行最后一个数据之后有一个空格。

输入中可能有重复元素，但是输出的二叉树遍历序列中重复元素不用输出。
示例1
输入
复制
5
1 6 5 9 8
输出
复制
1 6 5 9 8
1 5 6 8 9
5 8 9 6 1
 */

#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

struct TreeNode {
    int data;
    TreeNode* leftChild;
    TreeNode *rightChild;
    TreeNode(int m):
        data(m),leftChild(NULL),rightChild(NULL){}
};

TreeNode* insert(TreeNode* root,int x){
    if (root == NULL) {
        root = new TreeNode(x);
    } else if (x < root->data) {
        root->leftChild = insert(root->leftChild, x);
    } else if (x > root->data) {
        root->rightChild = insert(root->rightChild, x);
    }
    return root;
}

void PreOrder(TreeNode* root){
    if (root == NULL) {
        return;
    }
    printf("%d ", root->data);
    PreOrder(root->leftChild);
    PreOrder(root->rightChild);
}

void InOrder(TreeNode* root){
    if (root == NULL) {
        return;
    }
    InOrder(root->leftChild);
    printf("%d ", root->data);
    InOrder((root->rightChild));
}

void PostOrder(TreeNode* root){
    if (root == NULL) {
        return;
    }
    PostOrder(root->leftChild);
    PostOrder(root->rightChild);
    printf("%d ", root->data);
}

int main(){
    int n;
    while (scanf("%d", &n) != EOF) {
        TreeNode *root = NULL;
        for (int i = 0; i < n; ++i) {
            int k;
            scanf("%d", &k);
            root = insert(root,k);
        }
        PreOrder(root); printf("\n");
        InOrder(root); printf("\n");
        PostOrder(root);  printf("\n");
    }
    return 0;
}