'''
给你一个只包含 '(' 和 ')' 的字符串，找出最长有效（格式正确且连续）括号子串的长度。

 

示例 1：

输入：s = "(()"
输出：2
解释：最长有效括号子串是 "()"
示例 2：

输入：s = ")()())"
输出：4
解释：最长有效括号子串是 "()()"
示例 3：

输入：s = ""
输出：0
 

提示：

0 <= s.length <= 3 * 10^4
s[i] 为 '(' 或 ')'
'''
class Solution:
    def longestValidParentheses(self, s: str) -> int:
        """
        Args:
            s (str): '(()' ")()())" "()" "())"
        Returns:
            int: _description_
        """
        l = len(s)
        if l<2:
            return 0
        if s=="()":
            return 2
        max_len = 0
        stack = [s[0]]
        cur = 0
        for k,c in enumerate(s[1:]):
            k = k+1
            if c==')':
                if len(stack)==0:
                    stack.append(c)
                    continue
                if stack[-1]=='(':
                    stack.pop()
                    max_len = max(max_len, k-cur)
                else:
                    stack.append(c)
                    max_len = max(max_len, k-cur-1)
                    cur = k
            else:
                stack.append(c)
        return max_len

