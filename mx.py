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
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        pre = 0
        max_sum = 0
        for num in nums:
            pre = max(pre, pre+num)
            max_sum = max(pre, max_sum)

        return max_sum

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def func(nums):
            pivot = random.choice(nums)
            samll,qual,large = [],[],[]
            for num in nums:
                if num<pivot:
                    samll.append(num)
                elif num==pivot:
                    qual.append(num)
                else:
                    large.append(num)
            
            return func(samll)+qual+func(large)

class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        def func(nums, left, right):
            i,j = left,right
            pivot = nums[left]
            while i<j:
                while i<j and nums[j]>=pivot:
                    nums[i] = nums[j]
                while i<j and nums[i]<pivot:
                    nums[j] = nums[i]
                nums[i] = pivot
            func(nums, left, i-1)
            func(nums, i+1, right)
        func(nums,0,len(nums)-1)

class Solution:
    def twoSum(self, nums, target):
        record = {}
        for k,num in enumerate(nums):
            if target-num not in record:
                record[num] = k
            else:
                return [record[target-num], k]
class Solution:
    def longestPalindrome(self, s: str) -> str:
        res = ''
        record = {}
        for val in range(ord('0'), ord('9')+1):
            record[val] = []
        for val in range(ord('a'), ord('z')+1):
            record[val] = []
        for val in range(ord('A'), ord('Z')+1):
            record[val] = []
        for idx,val in enumerate(s):
            record[val].append(idx)
        for k,val in record.items():
            l = len(val)
            if l>1:
                for i in range(l-1):
                    for j in range(l, i, -1):
                        if j-i> len(res):
                            temp_s = s[i,j]
                            if temp_s==temp_s[::-1] and len(temp_s)>len(res):
                                res = temp_s
        return temp_s

class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        res = []
        queue = collections.deque()
        queue.append(root)
        while queue:
            layer = []
            for _ in range(len(queue)):
                node = queue.popleft()
                layer.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            res.append(layer)
        return res
class Solution:  
    def search(self, nums: List[int], target: int) -> int:
        left, right = 0, len(nums)-1
        while left<right:
            mid = (left+right)//2
            if target==nums[mid]:
                return mid
            if nums[left]<=nums[mid]:
                if nums[left]<=target<nums[mid]:
                    right = mid-1
                else:
                    left = mid+1
            else:
                if nums[mid]<target<=nums[right]:
                    left = mid+1
                else:
                    right = mid-1
class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        slow,fast = head,head
        while slow!=fast:
            if fast==None or fast.next==None:
                return False
            slow = slow.next
            fast = fast.next.next
        return True
class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        def func(root, p, q):
            if not root or root==p or root==q:
                return root
            left = func(root.left, p, q)
            right = func(root.right, p, q)
            if not left:
                return right
            if not right:
                return left
            return root
        return func(root, p, q)
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        res = []
        def func(x):
            if x==len(nums)-1:
                res.append(nums.copy())
            for j in range(x, len(nums)):
                nums[x], nums[j] = nums[j], nums[x]
                func(x+1)
                nums[x], nums[j] = nums[j], nums[x]
        return res
class Solution:
    def addStrings(self, num1: str, num2: str) -> str:
        res = ''
        full = 0
        i,j = len(num1)-1, len(num2)-1
        while i>=0 or j>=0:
            n1 = int(num1[i]) if i>=0 else 0
            n2 = int(num2[j]) if j>=0 else 0
            res = str((n1+n2)%10+full) + res
            full = (n1+n2)//10
            i -= 1
            j -= 1
        
        if full:
            return str(full)+res
        else:
            return res
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [1]*len(nums)
        for i in range(len(nums)):
            for j in range(i):
                if dp[i]>dp[j]:
                    dp[i] = max(dp[i], dp[j]+1)
        return max(dp)
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        tail = head
        for _ in range(n):
            tail = tail.next
        p = head
        pre = ListNode(0)
        one = pre
        pre.next = p
        while tail:
            p = p.next
            tail = tail.next
            pre = pre.next
        pre.next = p.next
        return one.next
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        
        nums = sorted(intervals)
        res = [nums[0]]
        for num in nums:
            if num[0]<=res[-1][1]:
                res[-1] = max(num[1], res[-1][1])
            else:
                res.append(num)
        return res

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

from collections import deque
class Solution:
    def rightSideView(self, root: Optional[TreeNode]) -> List[int]:
        res = []
        queue = deque()
        queue.append(root)

        while queue:
            layer = []
            for _ in range(len(queue)):
                node = queue.popleft()
                layer.append(node.val)
                if node.left:
                    queue.append(node.left)
                if node.right:
                    queue.append(node.right)
            res.append(layer)
        
        return [num[-1] for num in res]
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        i, j = 0, len(nums)-1
        while i<=j:
            mid = (i+j)//2
            if nums[mid]==target:
                return mid
            elif nums[i]<=target<nums[mid]:
                j = mid-1
            else:
                i = mid+1
        return -1
class MyQueue:

    def __init__(self):
        self.maxlen = 10
        self.stack1 = []
        self.stack2 = []

    def push(self, x: int) -> None:
        if len(self.stack1)<10:
            self.stack1.append(x)
        elif len(self.stack2)==0:
            while len(self.stack1)>0:
                temp = self.stack1.pop()
                self.stack2.append(temp)
            self.stack1.append(x)
        else:
            return -1

    def pop(self) -> int:
        if len(self.stack2)>0:
            x = self.stack2.pop()
            return x
        elif len(self.stack1)>0:
            while len(self.stack1)>0:
                temp = self.stack1.pop()
                self.stack2.append(temp)
            x = self.stack2.pop()
            return x
        else:
            return -1

    def peek(self) -> int:
        if len(self.stack2)>0:
            x = self.stack2[-1]
            return x
        elif len(self.stack1)>0:
            while len(self.stack1)>0:
                temp = self.stack1.pop()
                self.stack2.append(temp)
            x = self.stack2[-1]
            return x
        else:
            return -1

    def empty(self) -> bool:
        if len(self.stack1)==0 and len(self.stack2)==0:
            return True
        return False

class Solution:
    def mySqrt(self, x: int) -> int:
        i,j = 0,x
        while i<j:
            mid = (i+j+1)//2
            if mid**2<=x:
                i = mid
            else:
                j = mid-1    # 平方大的话就让值小点
        return -1
class Solution:
    def climbStairs(self, n: int) -> int:
        f1,f2 = 1,2    # n=1,n=2
        for _ in range(n-1):
            f1,f2 = f2,f1+f2
        return f1
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []
        def func(gen, left, right):
            if len(gen)==n*2:
                res.append(gen)
                return
            if left<n:
                gen.append('(')
                func(gen, left+1, right)
                gen.pop()
            if left>right:
                gen.append(')')
                func(gen, left, right+1)
                gen.pop()
        func([],0,0)
        return res
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def func(gene_res, left, right):
            if len(gene_res)==n*2:
                res.append(''.join(gene_res))
                return
            if left<n:
                gene_res.append('(')
                func(gene_res, left+1, right)
                gene_res.pop()
            if left>right:
                gene_res.append(')')
                func(gene_res, left, right+1)
                gene_res.pop()
        
        func([], 0, 0)
        return res
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        l3 = ListNode(0)
        p1,p2,p3 = l1,l2,l3
        full = 0
        while p1 or p2:
            n1 = p1.val if p1 else 0
            n2 = p2.val if p2 else 0
            temp = n1+n2+full
            node = ListNode(0)
            node.val = temp % 10
            full = temp // 10

            p3.next = node
            p3 = node
            if p1:
                p1 = p1.next
            if p2:
                p2 = p2.next
        if full:
            node = ListNode(1)
            p3.next = node
            p3 = node
        return l3.next
class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        i=0
        while i<len(nums):
            while nums[i] != nums[nums[i]-1] and 1<=nums[i]<=len(nums):
                self.check(nums, i, nums[i]-1)
            i += 1

        for i in range(len(nums)):
            if nums[i]-1 != i:
                return i+1
        return len(nums)+1
    def check(self,nums,index1,index2):
        temp = nums[index1]
        nums[index1] = nums[index2]
        nums[index2] = temp
# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        
        if not head:
            return
        nodelist = []
        p = head
        while p:
            nodelist.append(p)
            p = p.next
        i,j=0,len(nodelist)-1
        def func(nodelist, i, j):
            if i>=j:
                return
            left,right = i,j
            temp = nodelist[left]
            while left<right:
                while left<right and nodelist[right].val>=temp.val:
                    right -= 1
                nodelist[left] = nodelist[right]
                while left<right and nodelist[left].val<=temp.val:
                    left += 1
                nodelist[right] = nodelist[left]

            nodelist[left] = temp
            func(nodelist, i, left-1)
            func(nodelist, left+1, j)
        func(nodelist, i, j)
        head2 = nodelist[0]
        p = None
        for i in range(1, len(nodelist)):
            nodelist[i-1].next = nodelist[i]
            p = nodelist[i]
        if p:
            p.next = None
        return head2
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        n = len(inorder)
        inorder_record = {val:k for k,val in enumerate(inorder)}

        def func(preorderLeft, preorderRight, inorderLeft, inorderRight):
            # 递归结束
            if preorderLeft>preorderRight:
                return
            idx = inorder_record[preorder[preorderLeft]]
            root = TreeNode(preorder[preorderLeft])
            len_left_subtree = idx-inorderLeft
            root.left = func(preorderLeft+1, preorderLeft+len_left_subtree, inorderLeft, idx-1)
            root.right = func(preorderLeft+len_left_subtree+1, preorderRight, idx+1, inorderRight)
            return root
        return func(0,n-1, 0,n-1)
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """





import torch
import torch.nn as nn
import numpy as np
d_model = 512
n_heads = 8
d_q=d_k=d_v=64
d_ff = 2048
class MultiHeadAttention(nn.Module):
    def __init__(self):
        super(MultiHeadAttention, self).__init__()
        self.wq = nn.Linear(d_model, n_heads*d_q)
        self.wk = nn.Linear(d_model, n_heads*d_k)
        self.wv = nn.Linear(d_model, n_heads*d_v)
        self.fc = nn.Linear(n_heads*d_v, d_model)

    def forward(self, input_q, input_k, input_v, att_mask):
        """_summary_
        Args:
            input_q (_type_): [batch, len_q, d_model]
            input_k (_type_): [batch, len_q, d_model]
            input_v (_type_): [batch, len_q, d_model]
            att_mask (_type_): [batch, len_q, len_k]
        Returns:
            _type_: [batch, len_q, d_model]
        """
        residual, batch = input_q, input_q.size[0]
        Q = self.wq(input_q).view(batch, -1, n_heads, d_q).transpose(1,2)
        K = self.wk(input_k).view(batch, -1, n_heads, d_k).transpose(1,2)
        V = self.wv(input_v).view(batch, -1, n_heads, d_v).transpose(1,2)
        att_mask = att_mask.unsqueeze(1).repeat(1, n_heads, 1, 1)
        context, scores = ScalDotProduct(Q,K,V,att_mask)
        # 拼接多头
        context = context.transpose(1,2).reshape(batch, -1, n_heads*d_v)
        context = self.fc(context)
        return torch.Layer_norm(residual + context), scores

def ScalDotProduct(Q,K,V,att_mask):
    """_summary_
    Args:
        Q (_type_): [batch, n_heads, len_q, d_q]
        K (_type_): [batch, n_heads, len_k, d_k]
        V (_type_): [batch, n_heads, len_v, d_v]
        att_mask (_type_): [batch, n_heads, len_q, len_k]
    Returns:
        _type_: [batch, n_heads, len_q, d_v]
    """
    scores = torch.matmul(Q, K.T) / np.sqrt(d_model)
    scores.masked_fill_(att_mask, -1e9)
    scores = torch.softmax(d=-1)(scores)
    context = torch.matmul(scores, V)
    return context, scores
class FF(nn.Module):
    def __init__(self) -> None:
        super(FF, self).__init__()
        self.fc = nn.sequential(
            nn.Linear(d_model, d_ff),
            nn.ReLU(),
            nn.Linear(d_ff, d_model)
        )
    def forward(self, input):
        residual = input
        re = self.fc(input)
        return nn.layerNorm(d_model)(residual + re)
class EncoderLayer(nn.Module):
    def __init__(self) -> None:
        super(EncoderLayer, self).__init__()
        self.multiHeadAttention = MultiHeadAttention()
        self.ff = FF()
    def forward(self, enc_input, att_mask):
        """_summary_
        Args:
            enc_input (_type_): [batch, len_q, d_model]
            att_mask (_type_): [batch, len_q, len_k]
        Returns:
            _type_: [batch, len_q, d_model] [batch, len_q, len_k]
        """
        output, scores = self.multiHeadAttention(enc_input, enc_input, enc_input, att_mask)

        output = self.ff(output)
        return output, scores