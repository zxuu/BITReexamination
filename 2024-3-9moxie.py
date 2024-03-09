
# 3. 无重复字符的最长子串
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        window = []
        max_len = 0
        for k,c in enumerate(s):
            if c not in window:
                window.append(c)
                max_len = max(max_len, len(window))
            else:
                idx = window.index(c)
                window = [_ for _ in s[k+1-(len(window)-idx):k+1]]
        
        return max_len
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head) :
        # 头插法
        if not head:
            return head
        newhead = ListNode()
        p = head
        while p:
            q = p.next
            p.next = newhead.next
            newhead.next = p
            p = q
        return newhead.next
# 206. 反转链表
class Solution:
    def reverseList(self, head) :
        # 递归
        def func(pre, cur):
            if not cur:    # 终止条件
                return pre
            res = func(cur, cur.next)    # 返回翻转后的头结点
            # 回溯的时候顺道把指向给变了
            cur.next = pre    # 调换指向
            return res
        return func(None, head)
# 数组中第k大元素
import random
class Solution:
    def findKthLargest(self, nums, k):
        def func(nums, k):
            large, equal, small = [], [], []
            pivot = random.choice(nums)
            for num in nums:
                if num == pivot:
                    equal.append(num)
                elif num > pivot:
                    large.append(num)
                else:
                    small.append(num)
            if k <= len(large):
                return func(large, k)
            elif k > len(nums)-len(small):
                return func(small, k-(len(nums)-len(small)))
            return pivot
        return func(nums, k)