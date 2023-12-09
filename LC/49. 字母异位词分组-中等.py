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
import collections
from typing import List
class Solution(object):
    def groupAnagrams(self, strs):
        '''
        由于互为字母异位词的两个字符串包含的字母相同，
        因此对两个字符串分别进行排序之后得到的字符串一定是相同的，
        故可以将排序之后的字符串作为哈希表的键。
        '''
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
class Solution1:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        '''
        官方-排序
        由于互为字母异位词的两个字符串包含的字母相同，
        因此对两个字符串分别进行排序之后得到的字符串一定是相同的，
        故可以将排序之后的字符串作为哈希表的键。
        '''
        mp = collections.defaultdict(list)
        for st in strs:
            key = "".join(sorted(st))
            mp[key].append(st)    # 字符串作为键值 比 字符串数组作为键值速度快
        
        return list(mp.values())
class Solution2:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        '''
        官方-计数
        由于互为字母异位词的两个字符串包含的字母相同，因此两个字符串中的相同字母出现的次数一定是相同的，故可以将每个字母出现的次数使用字符串表示，作为哈希表的键。
        由于字符串只包含小写字母，因此对于每个字符串，可以使用长度为26的数组记录每个字母出现的次数。
        需要注意的是，在使用数组作为哈希表的键时，不同语言的支持程度不同，因此不同语言的实现方式也不同。
        '''
        mp = collections.defaultdict(list)

        for st in strs:
            counts = [0] * 26
            for ch in st:
                counts[ord(ch) - ord("a")] += 1    # ord()：Return the Unicode code point for a one-character string.
            # 需要将 list 转换成 tuple 才能进行哈希
            mp[tuple(counts)].append(st)
        
        return list(mp.values())


if __name__ == '__main__':
    s = Solution2().groupAnagrams(["eat", "tea", "tan", "ate", "nat", "bat"])
    print(s)