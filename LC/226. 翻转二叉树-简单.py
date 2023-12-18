'''
给你一棵二叉树的根节点 root ，翻转这棵二叉树，并返回其根节点。
'''
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:
        if not root:
            return root
        def func(curnode):
            if not curnode:
                return
            temp = curnode.left
            curnode.left = curnode.right
            curnode.right = temp
            func(curnode.left)
            func(curnode.right)
        
        return func(root)
