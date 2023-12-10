'''
给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。

请你设计并实现时间复杂度为 O(n) 的算法解决此问题。

 

示例 1：

输入：nums = [100,4,200,1,3,2]
输出：4
解释：最长数字连续序列是 [1, 2, 3, 4]。它的长度为 4。
示例 2：

输入：nums = [0,3,7,2,5,8,4,6,0,1]
输出：9
 

提示：

0 <= nums.length <= 10^5
-10^9 <= nums[i] <= 10^9
'''
from typing import List
class Solution(object):
    def longestConsecutive(self, nums: List[int]) -> int:
        '''官方：'''
        longest_streak = 0
        num_set = set(nums)    # 去重 & 从小到大排序

        for num in num_set:    # 遍历去过重的集合
            if num - 1 not in num_set:    # 如果num-1不在集合中（用这种方法减少不必要的枚举，从而时间复杂度从O(n^2)->O(n)
                current_num = num
                current_streak = 1
                while current_num + 1 in num_set:    # 不断遍历当前num大的数
                    current_num += 1
                    current_streak += 1

                longest_streak = max(longest_streak, current_streak)

        return longest_streak

if __name__ == '__main__':
    s = Solution().longestConsecutive([100,4,200,1,3,2])
    print(s)
