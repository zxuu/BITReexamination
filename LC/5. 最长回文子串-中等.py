'''
给你一个字符串 s，找到 s 中最长的回文子串。

如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。

 

示例 1：

输入：s = "babadb"
输出："bab"
解释："aba" 同样是符合题意的答案。
示例 2：

输入：s = "cbbd"
输出："bb"
 

提示：

1 <= s.length <= 1000
s 仅由数字和英文字母组成
'''
class Solution1:
    def longestPalindrome(self, s: str) -> str:     
        '''回文数左右两边必相等'''
        n = len(s)
        ans = s[0]
        if n == 1:
            return ans
        for i in range(n-1):
            for j  in range(i+len(ans), n):    # i+len(ans)快很多 9000ms->844ms
                if s[i] == s[j]:
                    res = s[i:j+1]
                    if res == res[::-1] and len(res) > len(ans):
                        ans = res                 
        return ans
from collections import defaultdict
class Solution:
    def longestPalindrome(self, s: str) -> str:
        '''哈希+双指针'''
        '''
        记录出现过的位置
        defaultdict(<class 'list'>, {'0': [], '1': [], '2': [], '3': [], '4': [], '5': [], '6': [], '7': [], '8': [], '9': [], 
        'a': [1, 3], 'b': [0, 2, 5], 'c': [], 'd': [4], 'e': [], 'f': [], 'g': [], 'h': [], 'i': [], 'j': [], 'k': [], 'l': [], 'm': [], 'n': [], 'o': [], 'p': [], 'q': [], 'r': [], 's': [], 't': [], 'u': [], 'v': [], 'w': [], 'x': [], 'y': [], 'z': [],
        'A': [], 'B': [], 'C': [], 'D': [], 'E': [], 'F': [], 'G': [], 'H': [], 'I': [], 'J': [], 'K': [], 'L': [], 'M': [], 'N': [], 'O': [], 'P': [], 'Q': [], 'R': [], 'S': [], 'T': [], 'U': [], 'V': [], 'W': [], 'X': [], 'Y': [], 'Z': []})'''
        res = s[0]
        if len(s)==1:
            return res
        tag = defaultdict(list)
        for i in range(ord('0'), ord('9')+1):
            tag[chr(i)]
        for i in range(ord('a'), ord('z')+1):
            tag[chr(i)]
        for i in range(ord('A'), ord('Z')+1):
            tag[chr(i)]
        for k,c in enumerate(s):
            tag[c].append(k)
        # # 删除没出现过的键 时间上升
        # d = []
        # for k,v in tag.items():
        #     if len(v)<2:
        #         d.append(k)
        # for key in d:
        #     del tag[key]
        for k,v in tag.items():
            l = len(v)
            i, j = 0, l-1
            for i in range(l-1):    # i从前往后
                for j in range(l-1, i, -1):    # j从后往前
                    if v[j]-v[i]<len(res):    # 减少没必要的寻找
                        break
                    sub_s = s[v[i] : v[j]+1]
                    len_subs = len(sub_s)
                    if sub_s == sub_s[::-1] and len_subs>len(res):
                        res = sub_s
        return res
        

if __name__ == '__main__':
    result = Solution().longestPalindrome('ccccc')
    print(result)