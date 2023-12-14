'''
给你一个整数数组 nums，请你将该数组升序排列。

 

示例 1：

输入：nums = [5,2,3,1]
输出：[1,2,3,5]
示例 2：

输入：nums = [5,1,1,2,0,0]
输出：[0,0,1,1,2,5]
 

提示：

1 <= nums.length <= 5 * 10^4
-5 * 10^4 <= nums[i] <= 5 * 10^4
'''
from typing import List
import random
# 快排
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def quick_sort(nums, left, right):
            if left>=right:
                return    # 递归终止
            temp_idx = random.randint(left, right)
            nums[left], nums[temp_idx] = nums[temp_idx], nums[left]
            temp = nums[left]
            i, j = left, right
            while i<j:
                # 需右指针先移动
                while i<j and nums[j]>=temp:
                    j -= 1
                nums[i] = nums[j]
                while i<j and nums[i]<=temp:
                    i += 1
                nums[j] = nums[i]
            
            nums[i] = temp
            quick_sort(nums, left, i-1)
            quick_sort(nums, i+1, right)
        quick_sort(nums, 0, len(nums)-1)
        return nums
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        if len(nums) <= 1:
            return nums
        
        pivot_index = random.randint(0,len(nums)-1)
        pivot = nums[pivot_index]

        # 大于，等于，小于三个数组
        le = [x for x in nums if x < pivot]
        eq = [x for x in nums if x == pivot]
        rt = [x for x in nums if x > pivot]

        return self.sortArray(le) + eq + self.sortArray(rt)

if __name__ == '__main__':
    result = Solution().sortArray([-2,1,-3,4,-1,2,1,-5,4])
    print(result)