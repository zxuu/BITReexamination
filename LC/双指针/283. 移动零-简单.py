'''
给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。

请注意 ，必须在不复制数组的情况下原地对数组进行操作。

 

示例 1:

输入: nums = [0,1,0,3,12]
输出: [1,3,12,0,0]
示例 2:

输入: nums = [0]
输出: [0]
 

提示:

1 <= nums.length <= 10^4
-2^31 <= nums[i] <= 2^31 - 1
 

进阶：你能尽量减少完成的操作次数吗？
'''
class Solution1:
    def moveZeroes(self, nums):
        '''
        记录非0个数直接替换，后面补充0就行
        nums = [0,1,0,3,12]
        '''
        sum_n0 = 0
        for num in nums:
            if num != 0:
                nums[sum_n0] = num
                sum_n0 += 1
        nums[sum_n0:] = [0]*(len(nums)-sum_n0)
        return nums
class Solution:
    def moveZeroes(self, nums):
        '''
        官方思路及解法
        使用双指针，左指针指向当前已经处理好的序列的尾部，右指针指向待处理序列的头部。
        右指针不断向右移动，每次右指针指向非零数，则将左右指针对应的数交换，同时左指针右移。
        注意到以下性质：
        左指针左边均为非零数；
        右指针左边直到左指针处均为零。
        因此每次交换，都是将左指针的零与右指针的非零数交换，且非零数的相对顺序并未改变。
        nums = [0,1,0,3,12]
        '''
        n = len(nums)
        left = right = 0
        while right < n:
            if nums[right] != 0:
                nums[left], nums[right] = nums[right], nums[left]
                left += 1
            right += 1
        return nums

if __name__ == '__main__':
    s = Solution1().moveZeroes([0,1,0,3,12])
    print(s)