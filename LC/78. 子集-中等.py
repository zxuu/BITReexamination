'''
给你一个整数数组 nums ，数组中的元素 互不相同 。返回该数组所有可能的子集（幂集）。

解集 不能 包含重复的子集。你可以按 任意顺序 返回解集。

 

示例 1：

输入：nums = [1,2,3]
输出：[[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
示例 2：

输入：nums = [0]
输出：[[],[0]]
 

提示：

1 <= nums.length <= 10
-10 <= nums[i] <= 10
nums 中的所有元素 互不相同
'''
from typing import List
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        '''输入：nums = [1,2,3]
            输出：[[],[1],[1,2],[1,2,3],[1,3],[2],[2,3],[3]]
        '''
        res = []
        l = len(nums)

        def func(idx, temp):
            # 添加
            res.append(temp)
            for j in range(idx, l):
                func(j+1, temp+[nums[j]])    # 回溯的话temp+[nums[j]]会不断地加后面的值
        func(0, [])
        return res