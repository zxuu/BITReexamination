'''
给你一个未排序的整数数组 nums ，请你找出其中没有出现的最小的正整数。

请你实现时间复杂度为 O(n) 并且只使用常数级别额外空间的解决方案。
 

示例 1：

输入：nums = [1,2,0]
输出：3
示例 2：

输入：nums = [3,4,-1,1]
输出：2
示例 3：

输入：nums = [7,8,9,11,12]
输出：1
 

提示：

1 <= nums.length <= 5 * 10^5
-2^31 <= nums[i] <= 2^31 - 1
'''
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        for i in range(len(nums)):
            # nums[i]要小于len
            # 巧妙，不断地交换
            # 在len的长度里，元素放到该到的位置
            while 1 <= nums[i] <= len(nums) and nums[i] != nums[nums[i] - 1]:
                self.check(nums, i, nums[i] - 1)
        for i in range(len(nums)):
            if nums[i] != i + 1:
                return i + 1
        return len(nums) + 1

    def check(self,nums,index1,index2):
        temp = nums[index1]
        nums[index1] = nums[index2]
        nums[index2] = temp

