from ast import List
from collections import defaultdict, deque
import collections
from typing import Optional
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None
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
# 146. LRU 缓存
    



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

#  三数之和等于0
class Solution(object):
    def threeSum(self, nums:list):
        res = []
        left = 0
        nums.sort()
        lenght = len(nums)
        for left in range(0, lenght-1):
            if left>0 and nums[left]==nums[left-1]:
                continue
            target = -nums[left]
            right = lenght-1
            for mid in range(left+1, right):
                if mid>left+1 and nums[mid]==nums[mid-1]:
                    continue
                while mid<right and nums[mid]+nums[right]>target:
                    right -= 1
                if mid==right:
                    break
                if nums[left]+nums[mid]+nums[right]==0:
                    res.append((nums[left], nums[mid], nums[right]))
        return res
# 53. 最大子数组和
class Solution:
    def maxSubArray(self, nums):
        pre = 0
        res = nums[0]
        for num in nums:
            # 遍历每一个元素，加上当前元素后下降了还不如不加，只要当期值就行。
            # 上升了更好
            pre = max(num, pre+num)
            res = max(res, pre)
        return res
# 912. 排序数组
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        if len(nums)==0:
            return nums
        # 也是分大中小三个列表
        pivot = random.choice(nums)
        large = [_ for _ in nums if _ > pivot]
        equal = [_ for _ in nums if _ == pivot]
        small = [_ for _ in nums if _ < pivot]
        # 迭代，返回三个表的拼接
        return self.sortArray(small) + equal + self.sortArray(large)
# 快排
class Solution:
    def sortArray(self, nums:List[int], i, j)->List[int]:
        def quickSort(nums, i, j):
            if i>j:
                return
            left, right = i, j
            pivot = nums[left]
            while left<right:
                while left<right and nums[right]>=pivot:
                    right -= 1
                nums[left] = nums[right]
                while left<right and nums[left]<=pivot:
                    left += 1
                nums[right] = nums[left]
            nums[left] = pivot
            quickSort(nums, i, left-1)
            quickSort(nums, left+1, j)
        quickSort(nums, 0, len(nums)-1)
        return nums
# 21. 合并两个有序链表
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        list3 = ListNode()
        l3 = list3
        p1, p2 = list1, list2
        while p1 and p2:
            q1, q2 = p1.next, p2.next
            if p1.val<=p2.val:
                p1.next = None
                p1.next = l3.next
                l3.next = p1
                l3 = p1
                p1 = q1
            else:
                p2.next = None
                p2.next = l3.next
                l3.next = p2
                l3 = p2
                p2 = q2
        while p1:
            q1 = p1.next
            p1.next = None
            p1.next = l3.next
            l3.next = p1
            l3 = p1
            p1 = q1
        while p2:
            q2 = p2.next
            p2.next = None
            p2.next = l3.next
            l3.next = p2
            l3 = p2
            p2 = q2
        
        return list3.next
# 1. 两数之和
class Solution:
    def twoSum(self, nums, target):
        records = dict()
        # 用枚举更方便，就不需要通过索引再去取当前位置的值
        for idx, val in enumerate(nums):
            if target - val not in records:
                records[val] = idx
            else:
                return [records[target - val], idx] # 如果存在就返回字典记录索引和当前索引
# 5. 最长回文子串
class Solution:
    def longestPalindrome(self, s: str) -> str:
        '''哈希+双指针'''
        '''
        defaultdict(<class 'list'>, {'0': [], '1': [], '2': [], '3': [], '4': [], '5': [], '6': [], '7': [], '8': [], '9': [], 
        'a': [1, 3], 'b': [0, 2, 5], 'c': [], 'd': [4], 'e': [], 'f': [], 'g': [], 'h': [], 'i': [], 'j': [], 'k': [], 'l': [], 'm': [], 'n': [], 'o': [], 'p': [], 'q': [], 'r': [], 's': [], 't': [], 'u': [], 'v': [], 'w': [], 'x': [], 'y': [], 'z': [],
        'A': [], 'B': [], 'C': [], 'D': [], 'E': [], 'F': [], 'G': [], 'H': [], 'I': [], 'J': [], 'K': [], 'L': [], 'M': [], 'N': [], 'O': [], 'P': [], 'Q': [], 'R': [], 'S': [], 'T': [], 'U': [], 'V': [], 'W': [], 'X': [], 'Y': [], 'Z': []})'''
        res = s[0]
        if len(res)==1:
            return res
        record = defaultdict(list)
        for _ in range(ord('0'), ord('9')+1):
            record[chr(_)]
        for _ in range(ord('a'), ord('z')+1):
            record[chr(_)]
        for _ in range(ord('A'), ord('Z')+1):
            record[chr(_)]
        for k,c in enumerate(s):
            record[c].append(k)
        for c, idx_list in record.items():
            lenght = len(idx_list)
            if lenght<2:
                continue
            for i in range(lenght-1):
                for j in range(lenght-1, i, -1):
                    if idx_list[j]-idx_list[i]+1<len(res):
                        break
                    sub_s = s[idx_list[i]: idx_list[j] + 1]
                    if sub_s == sub_s[::-1] and len(sub_s)>len(res):
                        res = sub_s
        return res
# 二叉树的层序遍历
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        deque = collections.deque()
        deque.append(root)
        while(deque):
            layer = []
            for _ in range(len(deque)):
                node = deque.popleft()
                layer.append(node.val)
                if node.left:
                    deque.append(node.left)
                if node.right:
                    deque.append(node.right)
            res.append(layer)
        return res
# 旋转数组查找
class Solution:  
    def search(self, nums: List[int], target: int) -> int:
        # 二分法查找，重要的是确定去哪边找。
        # 左边有序的话，看目标值在不在左边，在的话继续二分，不在的话去右边找。
        # 右边同理
        start = 0
        end = len(nums)-1
        while(start <= end):
            mid = (start + end) // 2
            # 左边有序
            if target==nums[mid]:
                return mid
            if nums[start]<=nums[mid]:
                if nums[start] <= target < nums[mid]:
                    end = mid-1
                else:
                    start = mid+1
            else:
                # 右边有序
                if nums[mid] < target <= nums[end]:
                    start = mid+1
                else:
                    end = mid-1
        return -1
# 20. 有效的括号
class Solution:
    def isValid(self, s: str) -> bool:
        lenght = len(s)
        if lenght==0 or lenght%2==1:
            return False
        stack = deque()
        record = {')':'(', ']':'[', '}':'{'}
        for c in s:
            if c=='(' or c=='[' or c=='{' :
                stack.append(c)
            else:
                if stack:
                    zifu = stack.pop()
                    if zifu==record[c]:
                        continue
                    else:
                        return False
                else:
                    return False
        if stack:
            return False
        else:
            return True
# 121. 买卖股票的最佳时机
class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        res = 0
        min_price = prices[0]    # 记录前面的最小价格
        for price in prices:
            res = max(res, price-min_price)
            min_price = min(price, min_price)
        return res
# 141. 环形链表
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        # 快慢指针
        if head==None or head.next==None:
            return False
        slow, fast = head, head.next
        while slow!=fast:
            # 退出条件
            if fast==None or fast.next==None:
                return False
            slow = slow.next
            fast = fast.next.next
        # slow == fast 有环
        return True
# 最近公共祖先节点
class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if root==None or root==p or root==q:
            return root
        left = self.lowestCommonAncestor(root.left, p, q)
        right = self.lowestCommonAncestor(root.right, p, q)
        if not left:
            return right
        if not right:
            return left
        return root
# 全排列
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        '''
        输入：nums = [1,2,3]
        输出：[[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
        '''
        lenght = len(nums)
        res = []
        def func(idx):
            if idx == lenght-1:
                res.append(nums[:])
                return
            for x in range(idx, lenght):
                nums[idx], nums[x] = nums[x], nums[idx]
                func(idx+1)
                nums[idx], nums[x] = nums[x], nums[idx]
        func(0)
        return res
# 88. 合并两个有序数组
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        """
        输入：nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
        nums1从后往前填，
        每次从num1、nums2尾部选最大的数填进nums1的尾部
        """
        p1, p2, p = m - 1, n - 1, m + n - 1
        while p2 >= 0:  # nums2 还有要合并的元素
            # 如果 p1 < 0(极端情况nums1中的数都比nums2中的大)，那么走 else 分支，把 nums2 合并到 nums1 中
            if p1 >= 0 and nums1[p1] > nums2[p2]:
                nums1[p] = nums1[p1]  # 填入 nums1[p1]
                p1 -= 1
            else:
                nums1[p] = nums2[p2]  # 填入 nums2[p1]
                p2 -= 1
            p -= 1  # 下一个要填入的位置
# 103. 二叉树的锯齿形层序遍历
class Solution:
    def zigzagLevelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        # 层次遍历
        res = []
        result = []
        if not root:
            return res
        deque = collections.deque()
        deque.append(root)
        while deque:
            layer = []
            node = deque.popleft()
            for _ in range(len(deque)):
                layer.append(node.val)
                if node.left:
                    deque.append(node.left)
                if node.right:
                    deque.append(node.right)
            res.append(layer)
        for i in range(len(res)):
            if i%2==0:
                result.append(res[i])
            else:
                result.append(res[::-1])
        return result
# 92. 反转链表 II
class Solution:
    def reverseBetween(self, head: Optional[ListNode], leftt: int, rightt: int) -> Optional[ListNode]:
        # 后插，前插，后插
        if not head or head.next==None:
            return head
        p = head
        new_l = ListNode()
        tail = new_l
        num = 0
        while p:
            num += 1
            if leftt<=num<=rightt:
                # 前插
                q = p.next
                p.next = tail.next
                tail.next = p
                p = q
            else:
                # 后插
                if num==rightt+1:

                    while tail.next:
                        tail = tail.next
                q = p.next
                p.next = tail.next
                tail.next = p
                tail = p
                p = q
        return new_l.next
# 160. 相交链表
class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        pa, pb = headA, headB
        lena, lenb = 0, 0
        longlist, shortlist = None, None
        while pa:
            lena += 1
            pa = pa.next
        while pb:
            lenb += 1
            pb = pb.next
        distance = 0
        if lena>lenb:
            longlist, shortlist = headA, headB
            distance = lena-lenb
        else:
            longlist, shortlist = headB, headA
            distance = lenb-lena
        while distance:
            longlist = longlist.next
            distance -= 1
        while longlist and shortlist:
            if longlist==shortlist:
                return longlist
            longlist = longlist.next
            shortlist = shortlist.next
        return None
# 字符串相加
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        res = ''
        jinwei = 0
        i,j = len(num1)-1, len(num2)-1
        while i>0 or j>0:
            n1 = int(num1[i]) if i>=0 else 0
            n2 = int(num2[j]) if j>=0 else 0
            sum_ = n1+n2+jinwei
            res = str(sum_%10) + res
            jinwei = sum_ // 10
            i -= 1
            j -= 1
        if jinwei:
            return str(jinwei)+res
        return res
# 300. 最长递增子序列
# Dynamic programming.
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        lenght = len(nums)
        if lenght==0:
            return 0
        dp = [1]*lenght
        for i in range(lenght):
            # 和前面的数比
            for j in range(i):
                if dp[j]<dp[i]:
                    dp[i] = max(dp[i], dp[j]+1)
        return max(dp)
# 42. 接雨水
class Solution:
    def trap(self, height):
        """
        官方
        :type height: List[int]
        :rtype: int
        """
        res = 0
        maxleft = maxright = 0
        left, right = 0, len(height)-1
        while left<right:
            maxleft = max(maxleft, height[left])
            maxright = max(maxright, height[right])
            if height[left]<height[right]:
                res += maxleft-height[left]
                left += 1
            else:
                res += maxright-height[right]
                right -= 1
        return res
# 142. 环形链表 II
class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if not head:
            return head
        slow=fast=head
        # 先找到相遇点
        while True:
            if not fast or not fast.next:
                # 无环
                return False
            slow, fast = slow.next, fast.next.next
            if slow == fast:
                break
        fast = head
        while slow != fast:
            slow, fast = slow.next, fast.next
        return fast
# 56. 合并区间
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        nums = intervals
        # 先排序
        nums = sorted(nums)
        res = [nums[0]]
        for num in nums:
            if num[0] <= res[-1][1]:
                res[-1][1] = max(res[-1][1], num[1])
            else:
                res.append(num)
        return res
# 19. 删除链表的倒数第 N 个结点
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        # 双指针
        l3 = ListNode()
        p = l3
        l3.next = tail = head
        for _ in range(n):
            tail = tail.next
        while tail:
            p = p.next
            tail = tail.next
        p.next = p.next.next
        return l3.next
# 94. 二叉树的中序遍历
class Solution:
    def inorderTraversal(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        def func(root):
            if not root:
                return
            func(root.left)
            res.append(root.val)
            func(root.right)
        func(root)
        return res
# 199. 二叉树的右视图
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        # 层序遍历
        if not root:
            return []
        deque = collections.deque()
        deque.append(root)
        res = []
        while deque:
            layer = []
            for _ in range(len(deque)):
                node = deque.popleft()
                layer.append(node.val)
                if node.left:
                    deque.append(node.left)
                if node.right:
                    deque.append(node.right)
            res.append(layer)
        return [_[-1] for _ in res]
# 704. 二分查找有序表
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        lenght = len(nums)
        if lenght==0:
            return -1
        left, right = 0, lenght-1
        while left<right:
            mid = (left+right)//2
            if nums[mid]==target:
                return mid
            elif nums[left]<=target<nums[mid]:
                right = mid-1
            else:
                left = mid+1
        return -1
