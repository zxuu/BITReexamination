'''
给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
你可以按任意顺序返回答案。

示例 1：
输入：nums = [2,7,11,15], target = 9
输出：[0,1]
解释：因为 nums[0] + nums[1] == 9 ，返回 [0, 1] 。
示例 2：
输入：nums = [3,2,4], target = 6
输出：[1,2]
示例 3：
输入：nums = [3,3], target = 6
输出：[0,1]

提示：
2 <= nums.length <= 104
-109 <= nums[i] <= 109
-109 <= target <= 109
只会存在一个有效答案

进阶：你可以想出一个时间复杂度小于 O(n^2) 的算法吗？
'''
class Solution(object):
    def twoSum(self, nums, target):
        """最简单的就是双指针遍历
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        for i in range(len(nums)):
            for j in range(i+1, len(nums)):
                if nums[i]+nums[j] == target:
                    return [i, j]
class Solution1(object):
    def twoSum(self, nums, target):
        """先sorted一下，O(n*logn)
        再双指针（一前一后）遍历
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = dict()
        for k,v in enumerate(nums):
            d[k]=v
        # 按值排序
        nums_dict = sorted(d.items(),  key=lambda d: d[1], reverse=False)
        i, j = 0, len(nums)-1
        while(i<j):
            if nums_dict[i][1]+nums_dict[j][1]==target:
                return [nums_dict[i][0], nums_dict[j][0]]
            elif nums_dict[i][1]+nums_dict[j][1]<target:
                i=i+1
            else:
                j=j-1
if __name__ == "__main__":
    solution = Solution1()
    print(solution.twoSum([3,2,3], 6))

