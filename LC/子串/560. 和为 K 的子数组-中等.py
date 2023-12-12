'''
给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
子数组是数组中元素的连续非空序列。

示例 1：
输入：nums = [1,1,1], k = 2
输出：2

示例 2：
输入：nums = [1,2,3], k = 3
输出：2
 
提示：
1 <= nums.length <= 2 * 10^4
-1000 <= nums[i] <= 1000
-10^7 <= k <= 10^7
'''
class Solution1:
    def subarraySum(self, nums, k):
        '''
        前缀和(时间复杂度：O(n^2)) 超时
        具体做法：开辟一个前缀和数组
        '''
        # 要求的连续子数组
        result = 0
        n = len(nums)
        # 前缀和数组
        preSum = [0]    # 前面加个0 [1,2,3]的preSum=[0,1,3,6]

        # 求前缀和数组
        tmp = 0
        for i in range(n):
            tmp += nums[i]
            preSum.append(tmp)
        
        # 求和为k的连续子数组，求i到j之间的和
        for i in range(1, n+1):
            for j in range(i, n+1):
                if preSum[j] - preSum[i-1] == k:  # preSum[j] - preSum[i-1]代表着在nums数组中，前j个数之和减去前i-1个数之和
                    result += 1
        
        return result

class Solution6:
    def subarraySum(self, nums, k):
        '''
        别人的最快的方法
        '''
        m ={0:1}    #** m的键值是前缀和
        accurent = 0
        result = 0
        for num in nums:    # 遍历nums
            accurent += num    # 前缀和（包括现在）

            if accurent - k in m:    # 当前位置的前缀和-k, 存在的话，中间存在和为k的片段
                result += m[accurent - k]
            
            # 更改前缀和的键
            if accurent in m:
                m[accurent]+=1
            else:
                m[accurent]=1
        return result

class Solution:
    def subarraySum(self, nums, k):
        '''
        默写别人的最快的方法
        '''
        result = 0
        prefixSumDict = {0:1}

        currentSum = 0

        for num in nums:
            currentSum += num
            if currentSum-k in prefixSumDict:
                result += prefixSumDict[currentSum-k]
            
            if currentSum in prefixSumDict:
                prefixSumDict[currentSum] += 1
            else:
                prefixSumDict[currentSum] = 1
        
        return result


if __name__ == '__main__':
    result = Solution().subarraySum([1,1,2,-1,-1,1], 2)
    print(result)