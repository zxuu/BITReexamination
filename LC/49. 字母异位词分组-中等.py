'''
给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。

字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

 

示例 1:

输入: strs = ["eat", "tea", "tan", "ate", "nat", "bat"]
输出: [["bat"],["nat","tan"],["ate","eat","tea"]]
示例 2:

输入: strs = [""]
输出: [[""]]
示例 3:

输入: strs = ["a"]
输出: [["a"]]
 

提示：

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] 仅包含小写字母
'''
class Solution(object):
    def groupAnagrams(self, strs):
        """
        字母异位词作为键值
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        unique = dict()
        for _ in strs:
            if len(_)==0:
                if '' not in unique:
                    unique[''] = ['']
                else:
                    unique[''].append('')
            else:
                if str(sorted(_)) not in unique:
                    unique[str(sorted(_))] = [_]
                else:
                    unique[str(sorted(_))].append(_)
        result = unique.values()
        return result

if __name__ == '__main__':
    s = Solution().groupAnagrams(["ddddddddddg","dgggggggggg"])
    print(s)