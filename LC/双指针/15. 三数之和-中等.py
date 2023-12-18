'''
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
同时还满足 nums[i] + nums[j] + nums[k] == 0 。请你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。
示例 1：

输入：nums = [-1,0,1,2,-1,-4]
输出：[[-1,-1,2],[-1,0,1]]
解释：
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0 。
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0 。
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0 。
不同的三元组是 [-1,0,1] 和 [-1,-1,2] 。
注意，输出的顺序和三元组的顺序并不重要。
示例 2：

输入：nums = [0,1,1]
输出：[]
解释：唯一可能的三元组和不为 0 。
示例 3：

输入：nums = [0,0,0]
输出：[[0,0,0]]
解释：唯一可能的三元组和为 0 。
 

提示：

3 <= nums.length <= 3000
-10^5 <= nums[i] <= 10^5
'''
class Solution1(object):
    def threeSum(self, nums):
        """
        暴力求解——超时
        :type nums: List[int] [-1,0,1,2,-1,-4]
        :rtype: List[List[int]]
        """
        nums = sorted(nums)
        print(nums)
        re = []
        left = 0
        while left<len(nums)-2:
            right = len(nums)-1
            while right-left>1:    # 
                for _ in range(left+1, right):
                    if nums[left]>0:
                        break
                    if nums[left]+nums[_]+nums[right] > 0:
                        break
                    if nums[_] == nums[_ - 1]:
                        continue
                    if nums[left]+nums[_]+nums[right] == 0:
                        re.append((nums[left], nums[_], nums[right]))
                right -= 1
            left += 1
        return list(set(re))
class Solution3(object):
    def threeSum(self, nums):
        """
        排序过后，从中间寻找
        :type nums: List[int] [-1,0,1,2,-1,-4]
        :rtype: List[List[int]]
        [-4, -1, -1, 0, 1, 2]
        """
        nums = sorted(nums)
        print(nums)
        

class Solution2:
    '''官方'''
    def threeSum(self, nums):
        n = len(nums)
        nums.sort()     # 先排序
        ans = list()    # 记录结果
        
        # 枚举 a
        for first in range(n):    # 左指针first
            # 需要和上一次枚举的数不相同（因为可能有重复值）
            if first > 0 and nums[first] == nums[first - 1]:    # 如果不是第一个 and 和上一个数重复，就不用枚举了
                continue
            # c 对应的指针初始指向数组的最右端
            third = n - 1    # 右指针
            target = -nums[first]    # 目标值：取负号之后，中间值和右边值之和要大于此值
            # 枚举 b
            for second in range(first + 1, n):    # 枚举中间指针
                # 需要和上一次枚举的数不相同
                if second > first + 1 and nums[second] == nums[second - 1]:
                    continue
                # 需要保证 b 的指针在 c 的指针的左侧
                while second < third and nums[second] + nums[third] > target:
                    third -= 1    # 中间指针固定， 右指针左移？
                # 如果指针重合，随着 b 后续的增加
                # 就不会有满足 a+b+c=0 并且 b<c 的 c 了，可以退出循环
                if second == third:
                    break
                if nums[second] + nums[third] == target:
                    ans.append([nums[first], nums[second], nums[third]])
        
        return ans
class Solution(object):
    def threeSum(self, nums):
        """
        copy官方
        :type nums: List[int] [-1,0,1,2,-1,-4]
        :rtype: List[List[int]]
        [-4, -1, -1, 0, 1, 2]
        """
        nums.sort()
        lenghth = len(nums)
        re = []    # 记录结果

        for left in range(lenghth):
            # 和左边相同就不用枚举
            if left>0 and nums[left]==nums[left-1]:
                continue
            right = lenghth-1    # 右指针
            target = -nums[left]    # 中间数和右边数的和要比这个大

            # 遍历中间数
            for mid in range(left+1, right):
                # 中间数和左边一样也不用遍历了
                if mid>left+1 and nums[mid]==nums[mid-1]:
                    continue

                # 移动右指针
                while mid<right and nums[mid]+nums[right]>target:
                    right -= 1
                if mid == right:    # 说明遍历完了也没有
                    break    # 
                # 看看满不满足条件，因为while完后不一定和为0
                if nums[left]+nums[mid]+nums[right]==0:
                    re.append((nums[left], nums[mid], nums[right]))
        return re


if __name__ == '__main__':
    re = Solution().threeSum([-1,0,1,2,-1,-4])
    print(re)