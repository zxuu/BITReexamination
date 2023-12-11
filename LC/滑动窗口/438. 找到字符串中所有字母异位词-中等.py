'''
给定两个字符串 s 和 p，找到 s 中所有 p 的 异位词 的子串，返回这些子串的起始索引。不考虑答案输出的顺序。

异位词 指由相同字母重排列形成的字符串（包括相同的字符串）。

 

示例 1:

输入: s = "cbaebabacd", p = "abc"
输出: [0,6]
解释:
起始索引等于 0 的子串是 "cba", 它是 "abc" 的异位词。
起始索引等于 6 的子串是 "bac", 它是 "abc" 的异位词。
 示例 2:

输入: s = "abab", p = "ab"
输出: [0,1,2]
解释:
起始索引等于 0 的子串是 "ab", 它是 "ab" 的异位词。
起始索引等于 1 的子串是 "ba", 它是 "ab" 的异位词。
起始索引等于 2 的子串是 "ab", 它是 "ab" 的异位词。
 

提示:

1 <= s.length, p.length <= 3 * 10^4
s 和 p 仅包含小写字母
'''
import collections
class Solution3(object):
    def findAnagrams(self, s, p):
        """
        窗口大小、内容都知道
        sorted(list())过程太耗时了。。。
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        result = []
        win_chars = sorted(list(p))
        s_len = len(s)
        p_len = len(p)
        for i in range(s_len - p_len+1):
            s_set = sorted(list(s[i:i+p_len]))
            if win_chars == s_set:
                result.append(i)
        
        return result
class Solution2(object):
    def findAnagrams(self, s, p):
        '''
        时间复杂度，空间复杂度都不太好(看别人的发现因为用了字典，改用标记数组比较好)
        '''
        result = []
        s_len, p_len = len(s), len(p)
        if s_len<p_len:
            return result
        # 初始化window_dict
        window_dict = collections.defaultdict(int)
        for i in range(ord('z')-ord('a')+1):
            window_dict[chr(ord('a')+i)] = 0
        for c in p:
            window_dict[c] += 1
        
        # 初始化s_dict()
        s_dict = collections.defaultdict(int)
        for i in range(ord('z')-ord('a')+1):
            s_dict[chr(ord('a')+i)] = 0
        for i in range(p_len):
            s_dict[s[i]] += 1

        if list(window_dict.values())==list(s_dict.values()):
            result.append(0)

        if s_len == p_len:
            return result
        for i in range(p_len, s_len):
            s_dict[s[i-p_len]] -= 1
            s_dict[s[i]] += 1
            if list(s_dict.values()) == list(window_dict.values()):
                result.append(i-p_len+1)

        return result
class Solution1(object):
    def findAnagrams(self, s, p):
        """
        别人的（最好的）
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        res = []
        if len(p) > len(s):
            return res
        if len(p) == len(s):
            if "".join(sorted(p)) == "".join(sorted(s)):
                res.append(0)
            return res
        s_count = [0] * 26    # 26个字母
        p_count = [0] * 26

        for i in range(len(p)):
            s_count[ord(s[i]) - 97] += 1     # 97：a
            p_count[ord(p[i]) - 97] += 1
        if s_count == p_count:
            res.append(0)
        size_p = len(p)
        for i in range(len(s) - size_p):
            s_count[ord(s[i])-97] -= 1
            s_count[ord(s[i+size_p]) - 97] += 1
            if s_count == p_count:
                res.append(i+1)
        return res

class Solution(object):
    def findAnagrams(self, s, p):
        '''
        时间复杂度，空间复杂度都不太好(看别人的发现因为用了字典，改用标记数组比较好)
        '''
        result = []
        s_len, p_len = len(s), len(p)
        if s_len<p_len:
            return result
        # 初始化window_dict
        window_list = [0]*26
        for c in p:
            window_list[ord(c)-ord('a')] += 1
        
        # 初始化s_dict()
        s_list = [0]*26
        for i in range(p_len):
            s_list[ord(s[i])-ord('a')] += 1

        if window_list==s_list:
            result.append(0)

        if s_len == p_len:
            return result
        for i in range(p_len, s_len):
            s_list[ord(s[i-p_len])-ord('a')] -= 1
            s_list[ord(s[i])-ord('a')] += 1
            if window_list == s_list:
                result.append(i-p_len+1)

        return result

if __name__ == '__main__':
    result = Solution().findAnagrams(s="abab",p="ab")
    print(result)