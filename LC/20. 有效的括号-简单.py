'''
给定一个只包括 '('，')'，'{'，'}'，'['，']' 的字符串 s ，判断字符串是否有效。

有效字符串需满足：

左括号必须用相同类型的右括号闭合。
左括号必须以正确的顺序闭合。
每个右括号都有一个对应的相同类型的左括号。
 

示例 1：

输入：s = "()"
输出：true
示例 2：

输入：s = "()[]{}"
输出：true
示例 3：

输入：s = "(]"
输出：false
 

提示：

1 <= s.length <= 10^4
s 仅由括号 '()[]{}' 组成
'''
from collections import deque
class Solution:
    def isValid(self, s: str) -> bool:
        """
        Args:
            s (str): '()[]{}'
        Returns:
            bool: true
        """
        l = len(s)
        if l==0 or l%2!=0:
            return False
        stack = deque()
        for c in s:
            if c=='(' or c=='[' or c=='{':
                stack.append(c)
                continue
            elif c==')':
                if stack:
                    temp = stack.pop()
                    if temp != '(':
                        return False
                    else:
                        continue
                else:
                    return False
            elif c==']':
                if stack:
                    temp = stack.pop()
                    if temp != '[':
                        return False
                    else:
                        continue
                else:
                    return False
            elif c=='}':
                if stack:
                    temp = stack.pop()
                    if temp != '{':
                        return False
                    else:
                        continue
                else:
                    return False

        if len(stack)!=0:
            return False
        else:
            return True

if __name__ == '__main__':
    result = Solution().isValid("){")
    print(result)