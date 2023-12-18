'''
数字 n 代表生成括号的对数，请你设计一个函数，用于能够生成所有可能的并且 有效的 括号组合。

 

示例 1：

输入：n = 3
输出：["((()))","(()())","(())()","()(())","()()()"]
示例 2：

输入：n = 1
输出：["()"]
 

提示：

1 <= n <= 8
'''
from typing import List
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def func(gene_res, left, right):
            if len(gene_res)==n**2:
                res.append(''.join(gene_res))
                return
            if left<n:
                gene_res.append('(')
                func(gene_res, left+1, right)
                gene_res.pop()
            if left>right:
                gene_res.append(')')
                func(gene_res, left, right+1)
                gene_res.pop()
        
        func(res, 0, 0)
        return res