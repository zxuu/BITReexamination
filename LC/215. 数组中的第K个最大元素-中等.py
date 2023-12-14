'''
给定整数数组 nums 和整数 k，请返回数组中第 k 个最大的元素。

请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。

你必须设计并实现时间复杂度为 O(n) 的算法解决此问题。

 

示例 1:

输入: [3,2,1,5,6,4], k = 2
输出: 5
示例 2:

输入: [3,2,3,1,2,4,5,5,6], k = 4
输出: 4
 

提示：

1 <= k <= nums.length <= 10^5
-10^4 <= nums[i] <= 10^4
'''
import random
class Solution:
    def findKthLargest(self, nums, k):
        def quick_select(nums, k):
            # 随机选择基准数
            pivot = random.choice(nums)
            # 将大于、小于、等于 pivot 的元素划分至 big, small, equal 中
            big, equal, small = [], [], []
            for num in nums:
                if num > pivot:
                    big.append(num)
                elif num < pivot:
                    small.append(num)
                else:
                    equal.append(num)
            
            if k <= len(big):
                # 第 k 大元素在 big 中，递归划分
                return quick_select(big, k)
            if k > len(nums) - len(small):
                # 第 k 大元素在 small 中，递归划分(但已经不是找第K大了)
                return quick_select(small, k - (len(nums) - len(small)))
            
            # 第 k 大元素在 equal 中，直接返回 pivot
            return pivot
class Solution:
    def findKthLargest(self, nums, k):
        def quick_select(nums, k):
            pivot = random.choice(nums)
            large, equal, small = [], [], []

            for num in nums:
                if num>pivot:
                    large.append(num)
                elif num == pivot:
                    equal.append(num)
                else:
                    small.append(num)
            
            if k <= len(large):
                return quick_select(large, k)
            if k > len(nums)-len(small):
                return quick_select(small, k-(len(nums)-len(small)))
            
            return pivot