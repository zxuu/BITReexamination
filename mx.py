class Solution(object):
    def lengthOfLongestSubstring(self, s):
        window = []
        max_len = 0
        for k,c in enumerate(s):
            if c not in window:
                window.append(c)
            else:
                max_len = max(max_len, len(window))
                idx = window.index(c)

                window = [_ for _ in s[k+1-(len(window)-idx):(k+1)]]
        
        max_len = max(max_len, len(window))
        return max_len
    
class Solution:
    def findKthLargest(self, nums, k):

        def func(nums, k):
            pivot = random.choice(nums)
            small, qual, large = [],[],[]
            for num in nums:
                if num<pivot:
                    small.append(num)
                elif num == pivot:
                    qual.append(num)
                else:
                    large.append(num)
            if k<=len(large):
                return func(large, k)
            elif k>len(nums)-len(small):
                return func(small, k-(len(nums)-len(small)))
            return pivot
        return func(nums, k)

class Solution(object):
    def threeSum(self, nums):
        res = []
        for left in range(nums):
            if left>0 and nums[left]==nums[left-1]:
                continue
            right = len(nums)-1
            target = -nums[left]
            for mid in range(left+1, right):
                if mid>left+1 and nums[mid]==nums[mid-1]:
                    continue
                if nums[left]+nums[mid]+nums[right]>target:
                    right -= 1
                if mid==right:
                    break
                if nums[left]+nums[mid]+nums[right]==0:
                    res.append((left, mid, right))
        
        return res