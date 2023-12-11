'''
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: s = "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: s = "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: s = "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
    请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。
 

提示：

0 <= s.length <= 5 * 10^4
s 由英文字母、数字、符号和空格组成
'''
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str "abcaabcbb"
        :rtype: int
        """
        s_len = len(s)
        max_winlen = 0
        window = []
        for k,c in enumerate(s):
            if c not in window:
                window.append(c)
                max_winlen = max(max_winlen, len(window))
            else:    # 此时c在窗口中
                max_winlen = max(max_winlen, len(window))
                idx = window.index(c)
                # new window
                # 把窗口截取一部分再加上当前位置作为新的窗口
                window = [_ for _ in s[k+1-(len(window)-idx):k+1]]
                max_winlen = max(max_winlen, len(window))
        
        return max_winlen




if __name__ == '__main__':
    result = Solution().lengthOfLongestSubstring(" ")
    print(result)