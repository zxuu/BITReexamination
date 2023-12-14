'''
给你一个整数数组 nums ，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

子数组 是数组中的一个连续部分。

 

示例 1：

输入：nums = [-2,1,-3,4,-1,2,1,-5,4]
输出：6
解释：连续子数组 [4,-1,2,1] 的和最大，为 6 。
示例 2：

输入：nums = [1]
输出：1
示例 3：

输入：nums = [5,4,-1,7,8]
输出：23
 

提示：

1 <= nums.length <= 105
-104 <= nums[i] <= 104
 

进阶：如果你已经实现复杂度为 O(n) 的解法，尝试使用更为精妙的 分治法 求解。
'''
from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        """
        Args:
            nums (List[int]): [-2,1,-3,4,-1,2,1,-5,4]
        Returns:
            int: 6
        """
        pre = 0
        res = nums[0]
        for i in range(len(nums)):
            pre = max(nums[i], pre + nums[i])    # 如果前面的和（不一定是全部前面）+当前值 < 当前值
                                                 # 那就从当前位置开始计数 
            res = max(res, pre)
        return res

if __name__ == '__main__':
    result = Solution().maxSubArray([-2,1,-3,4,-1,2,1,-5,4])
    print(result)

class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        pre = 0
        res = nums[0]
        for num in nums:
            pre = max(num, pre+num)
            res = max(res, pre)
        
        return res