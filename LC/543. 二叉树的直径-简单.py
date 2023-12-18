'''
给你一棵二叉树的根节点，返回该树的 直径 。

二叉树的 直径 是指树中任意两个节点之间最长路径的 长度 。这条路径可能经过也可能不经过根节点 root 。

两节点之间路径的 长度 由它们之间边数表示。
'''
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution:
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        '''每个节点记录左右子树深度'''
        res = 0
        def func(curnode):
            if not curnode:
                return 0
            left = func(curnode.left)
            right = func(curnode.right)
            return max(res, res+left+right)
        func(root)
        return res
