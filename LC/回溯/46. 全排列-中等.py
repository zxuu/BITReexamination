'''
给定一个不含重复数字的数组 nums ，返回其 所有可能的全排列 。你可以 按任意顺序 返回答案。

 

示例 1：

输入：nums = [1,2,3]
输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
示例 2：

输入：nums = [0,1]
输出：[[0,1],[1,0]]
示例 3：

输入：nums = [1]
输出：[[1]]
 

提示：

1 <= nums.length <= 6
-10 <= nums[i] <= 10
nums 中的所有整数 互不相同
'''
class Solution2:
    def permute(self, nums):
        """
        :type nums: List[int] [1,2,3]
        :rtype: List[List[int]]
        [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
        """
        def backtrack(first = 0):
            # 所有数都填完了
            if first == n:  
                res.append(nums[:])
            for i in range(first, n):
                # 动态维护数组
                nums[first], nums[i] = nums[i], nums[first]
                # 继续递归填下一个数
                backtrack(first + 1)
                # 撤销操作
                nums[first], nums[i] = nums[i], nums[first]
        
        n = len(nums)
        res = []
        backtrack()
        return res

class Solution1:
    def permute(self, nums):
        '''other fasteast'''
        result = []
        lenght = len(nums)
        
        def f1(start):
            # 所有数都填完了
            if start >= lenght:
                result.append(nums[:])
            else:
                for i in range(start, lenght):
                    # 动态维护数组
                    nums[start], nums[i] = nums[i], nums[start]
                    # 继续递归填下一个数
                    f1(start + 1)
                    # 撤销操作
                    nums[start], nums[i] = nums[i], nums[start]
                
        f1(0)
        return result
from typing import List
class Solution6:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        def dfs(x):
            if x == len(nums) - 1:
                res.append(list(nums))   # 添加排列方案
                return
            
            for i in range(x, len(nums)):
                nums[i], nums[x] = nums[x], nums[i]  # 交换，将 nums[i] 固定在第 x 位
                dfs(x + 1)                           # 开启固定第 x + 1 位元素
                nums[i], nums[x] = nums[x], nums[i]  # 恢复交换

        dfs(0)
        return res



'''默写'''
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        lenght = len(nums)
        def bl(x):    # 固定x位置
            if x==lenght-1:
                res.append(nums.copy())
                return
            for i in range(x, lenght):
                nums[i],nums[x] = nums[x],nums[i]
                bl(x+1)
                nums[i],nums[x] = nums[x],nums[i]
        bl(0)
        return res
if __name__ == '__main__':
    result = Solution().permute([1,2,3,4])
    print(result)