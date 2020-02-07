/*
层次遍历
 */

#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

struct TreeNode{
    int data;
    TreeNode *leftChild;
    TreeNode *rightNode;
};

void visite(TreeNode* current){
    printf("%d\n", current->data);
}

void LevelOrder(TreeNode* root){
    queue<TreeNode*> myQueue;
    if (root != NULL) {
        myQueue.push(root);
    }
    while (!myQueue.empty()) {
        TreeNode *current = myQueue.front();
        myQueue.pop();
        visite(current);
        if (current->leftChild != NULL) {
            myQueue.push(current->leftChild);
        }
        if (current->rightNode != NULL) {
            myQueue.push(current->rightNode);
        }
    }

}

int main(){

    return 0;
}
