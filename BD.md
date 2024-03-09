#### 数组中地k大元素
```python
class Solution():
    def findK(self, nums, k):

        def func(S, k):
            large, qual, small = [], [], []
            pivot = random.choice(S)
            # 遍历一遍填充
            for ele in S:
                if ele>pivot:
                    large.append(ele)
                if ele<pivote:
                    small.append(ele)
                else:
                    qual.append(ele)
            #
            if k<=len(large):
                return func(large, k)
            if k>len(nums)-len(small):
                return func(small, k-(len(num)-len(small)))
            return pivot

        return func(nums, k)
```
#### 对称二叉树
```python
class Solution:
    def isSymmetric(self, root: Optional[TreeNode]) -> bool:
        # 左右一样，左的左和又得又一样，左的又和又的左一样
        def func(left, right):
            # 结束条件
            if not left and not right:
                return True
            if not left or not right or left.val!=right.val:
                return False
            
            return func(left.left, right.right) and func(left.right, right.left)

        return func(root.left, root.right)
```
#### 环形链表入口
```python
class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        # 先找第一次相遇点
        slow, fast = head, head
        while True:
            if not (fast or fast.next):
                return False
            slow, fast = slow.next, fast.next.next
            if slow==fast:
                return fast     # 相遇点
        fast = head
        # 第二次相遇就是入口
        while slow!=fast:
            slow, fast = slow.next, fast.next.next
        return fast    # 入口
```
#### 全排列
```python
class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        # 不断地固定x的位置
        res = []
        lenght = len(nums)
        def func(x):
            # 如果最后一个数
            if x == lenghth-1:
                res.append(nums.copy())
            
            for i in range(x, lenghth):
                nums[i], nums[x] = nums[x], nums[i]
                func(x+1)
                # 撤销
                nums[i], nums[x] = nums[x], nums[i]
        
        func(0)

        return res
```
#### 最长递增子序列
```python
# Dynamic programming.
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = [1]*len(nums)
        for i in range(len(nums)):
            for j in range(i):
                if nums[j] < nums[i]:
                    dp[i] = max(dp[i], dp[j]+1)
        
        return max(dp)

```
#### 最大子数组和
```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        # 前缀和加自己比自己还小，那不如不加。自己就是前缀和
        pre = 0
        res = nums[0]
        for i in range(len(nums)):
            pre = max(pre, pre+nums[i])
            res = max(res, pre)
        
        return res
```
#### 奇数调到偶数前面
```python
class Solution:
    def trainingPlan(self, actions: List[int]) -> List[int]:
        i,j = 0, len(actions)-1
        while i<j:
            while i<j and actions[i]%2==1:
                i += 1
            while i<j and actions[j]%2==0:
                j -= 1
            actions[i], actions[j] = actions[j], actions[i]

        return actions
```
#### 最长连续序列长度
```python
class Solution(object):
    def longestConsecutive(self, nums):
        max_len = 0
        nums = set(nums)
        for num in mums:
            if num-1 not in nums:
                curnum = num
                curlen = 1
                while curnum+1 in nums:
                    curnum  += 1
                    curlen += 1
                max_len = max(max_len, curlen)
        return max_len

```
```python
class MultiHeadAttention(nn.Moudel):
    def __init__(self):
        super(MultiHeadAttention, self).__init__()
        self.wq = nn.Linear(d_model, n_heads*d_q)
        self.wk = nn.Linear(d_model, n_heads*d_k)
        self.wv = nn.Linear(d_model, n_heads*d_v)

        self.fc = nn.Linear(n_heads*d_v, d_model)
    def forward(self, input_q, input_k, input_v, att_mask):
        """
        input_q: [batch, len_q, d_model]
        input_k: [batch, len_k, d_model]
        input_v: [batch, len_v, d_model]
        att_mask: [batch, len_q, len_k]
        """
        residual, batch = input_q, input_q.size[0]
        Q = self.wq(input_q).view(batch, -1, n_heads, d_q).transpose(1,2)
        K = self.wk(input_k).view(batch, -1, n_heads, d_k).transpose(1,2)
        V = self.wv(input_v).view(batch, -1, n_heads, d_v).transpose(1,2)

        att_mask = att_mask.unsqueeze(1).repeat(1, n_heads, 1, 1)

        context, att_scores = ScalDotProductAttention(Q, K, V, att_mask)

        #拼接多头
        context = context.transpose(1,2).reshape(batch, len_q, n_heads*d_v)
        context = self.fc(context)     # [batch, len_q, d_model]
        return torch.LayerNormal(d_model)(residual+context)


def ScalDotProductAttention(Q, K, V, att_mask):
    """
    Q: [batch, n_heads, len_q, d_q]
    K: [batch, n_heads, len_k, d_k]
    V: [batch, n_heads, len_v, d_v]
    att_mask: [batch, n_heads, len_q, len_k]
    """
    scores = torch.matmul(Q, k.transpose(-1,-2)) / np.sqrt(d_model)
    scores.maskfill(att_mask, -1e9)
    scores = torch.softmax(dim=-1)(scores)    # [batch, n_heads, len_q, len_k]

    context = torch.matmul(scores, V)    # [batch, n_heads, len_q, d_v]
    return context, scores
```
#### 搜索二维矩阵
```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        i, j = len(matrix)-1, 0
        while i>=0 and j<len(matrix[0]):
            if target<matrix[i][j]:
                i -= 1
            elif target>matrix[i][j]:
                j += 1
            else:
                return True
        return False
```
#### 无重复字符的最长子串
```python
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        max_len = 0
        window = []

        # 遍历
        for k,c in enumerate(s):
            if c not in window:
                window.append(c)
                max_len = max(max_len, len(window))
            else:    # 当前字符串不在窗口中
                idx = window.index(c)
                # 更换窗口
                window = [_ for _ in s[k+1-(len(window)-idx) : k+1]]
        
        return max_len
```
####  LRU (最近最少使用) 缓存 约束的数据结构。
```python
class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cap = []
        # self.deque = collections.deque()

    def get(self, key: int) -> int:
        if key not in [_[0] for _ in self.cap]:
            return -1
        else:     # 有该键 返回值&移动
            idx = [_[0] for _ in self.cap].index(key)
            res =  self.cap[idx][1]    # 返回值
            # 移动
            for i in range(idx-1, -1, -1):
                self.cap[i+1] = self.cap[i]
            self.cap[i] = [key, res]

            return res
    def put(self, key: int, value: int) -> None:
        kl = [_[0] for _ in self.cap]
        if key in kl:
            idx = kl.index(key)
            self.cap[idx][1]=value
        elif len(self.cap)>=self.capacity:
            self.cap.pop()
            self.cap.append([key, value])
            # 移动
            idx = len(self.cap)-2
            for i in range(idx-1, -1, -1):
                self.cap[i+1] = self.cap[i]
            self.cap[i] = [key, value]
        else:
            self.cap.append([key, value])
            # 移动
            idx = len(self.cap)-2
            for i in range(idx-1, -1, -1):
                self.cap[i+1] = self.cap[i]
            self.cap[i] = [key, value]






# Your LRUCache object will be instantiated and called as such:
# obj = LRUCache(capacity)
# param_1 = obj.get(key)
# obj.put(key,value)
```
####  三数之和等于0
```python
class Solution(object):
    def threeSum(self, nums):
        res = []
        nums.sort()
        l = len(nums)
        for left in range(0, l):
            # 遍历过了
            if left>0 and nums[left]==nums[left-1]:
                continue
            
            right = l-1
            target = -nums[left]    # ***

            for mid in range(left+1, right):
                if mid>left+1 and nums[mid]==nums[mid-1]:
                    continue
                while mid<right and nums[mid]+nums[right]>target:
                    right -= 1
                if mid == right:
                    break
                if nums[left]+nums[mid]+nums[right]==0:
                    res.append((nums[left],nums[mid],nums[right]))
        
        return res
```
####  最大子数组和
```python
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        pre = 0
        max_sum = 0
        for i in range(len(nums)):
            pre = max(nums[i], pre+nums[i])
            max_sum = max(max_sum, pre)
        return max_sum
```
####  快排
```python
class Solution:
    def quick_sort(self, nums: List[int]) -> List[int]:
        def quickSort(nums, left, right):
            i, j = left, right
            while left<right:
                while left<right and nums[right]>=pivot:
                    right -= 1
                nums[left] = nums[right]
                while left<right and nums[left]<=pivot:
                    left+=1
                nums[right] = nums[left]
            nums[left] = pivot
            quickSort(nums, i, left-1)
            quickSort(nums, left+1, j)
        quickSort(nums, 0, len(nums))
        return nums
```
####  快排
```python
class Solution:
    def quick_sort(self, nums: List[int]) -> List[int]:
        def quickSort(nums):
            if len(nums)<=1:
                return nums
            pivot_idx = random.randint(0, len(nums)-1)
            pivot = nums[pivot_idx]
            # 大于，等于，小于三个数组
            small = [num for num in nums if num<pivot]
            equal = [num for num in nums if num==pivot]
            large = [num for num in nums if num>pivot]

            return quick_sort(small) + equal + quick_sort(large)
        return quick_sort(nums)
```
####  两数之和
```python
class Solution:
    def twoSum(self, nums, target):
        record = {}
        for k,v in enumerate(nums):
            if target-v not in record:
                record[v] = k
            else:
                return [record[target-v], k]
```
#### 最长回文子串
```python
class Solution:
    def longestPalindrome(self, s: str) -> str:
        '''哈希+双指针'''
        '''
        defaultdict(<class 'list'>, {'0': [], '1': [], '2': [], '3': [], '4': [], '5': [], '6': [], '7': [], '8': [], '9': [], 
        'a': [1, 3], 'b': [0, 2, 5], 'c': [], 'd': [4], 'e': [], 'f': [], 'g': [], 'h': [], 'i': [], 'j': [], 'k': [], 'l': [], 'm': [], 'n': [], 'o': [], 'p': [], 'q': [], 'r': [], 's': [], 't': [], 'u': [], 'v': [], 'w': [], 'x': [], 'y': [], 'z': [],
        'A': [], 'B': [], 'C': [], 'D': [], 'E': [], 'F': [], 'G': [], 'H': [], 'I': [], 'J': [], 'K': [], 'L': [], 'M': [], 'N': [], 'O': [], 'P': [], 'Q': [], 'R': [], 'S': [], 'T': [], 'U': [], 'V': [], 'W': [], 'X': [], 'Y': [], 'Z': []})'''
        res = s[0]
        if len(s)==1:
            return res
        tag = defaultdict(list)
        for i in range(ord('0'), ord('9')+1):
            tag[chr(i)]
        for i in range(ord('a'), ord('z')+1):
            tag[chr(i)]
        for i in range(ord('A'), ord('Z')+1):
            tag[chr(i)]
        for k,c in enumerate(s):
            tag[c].append(k)
        for k,v in tag.items():
            l = len(v)
            i, j = 0, l-1
            for i in range(l-1):    # i从前往后
                for j in range(l-1, i, -1):    # j从后往前
                    if v[j]-v[i]<len(res):    # 减少没必要的寻找
                        break
                    sub_s = s[v[i] : v[j]+1]
                    len_subs = len(sub_s)
                    if sub_s == sub_s[::-1] and len_subs>len(res):
                        res = sub_s
        return res
```
#### 二叉树的层序遍历
```python
class Solution:
    def levelOrder(self, root: Optional[TreeNode]) -> List[List[int]]:
        deque = collections.deque()
        deque.append(root)
        res = []
        while deque:
            layer = []
            for _ in range(len(deque)):
                tempnode = deque.popleft()    # pop左边 先进先出
                layer.append(tempnode.val)
                if tempnode.left:
                    deque.append(tempnode.left)
                if tempnode.right:
                    deque.append(tempnode.right)
            res.append(layer)
        return res
```
#### **33. 搜索旋转排序数组**
```python
class Solution:  
    def search(self, nums: List[int], target: int) -> int:  
        start = 0
        end = len(nums)-1

        while start<end:
            mid = (start+end) // 2

            if nums[mid] == target:
                return mid
            
            # 左边有序的
            if nums[mid] > nums[start]:
                if nums[start]<= target < nums[mid]:
                    end = mid - 1
                else:
                    start = mid + 1
            else:    # 右边有序
                if nums[mid]< target <= nums[end]:
                    start = mid + 1
                else:
                    end = mid - 1
        
        return -1
```
#### 二叉树的最近公共祖先
```python
class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        def func(node):
            '''先序遍历'''
            # 终止条件
            # 空节点、遍历到了p、q节点（也就是说，只可能反回p or q 或空节点）
            if not root or root == p or root == q:    # 空节点、遍历到了p、q节点
                return root

            left = self.lowestCommonAncestor(root.left, p, q)
            right = self.lowestCommonAncestor(root.right, p, q)
            if not left:    # 左为空，右边爱啥啥
                return right
            if not right:    # 左边有p or q了，右为空，直接返回左
                return left
            return root    # p and q分布在异侧，返回当前节点（此节点就是公共祖先节点）
        return func(root)
```
#### **括号生成**
```python
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        res = []

        def func(res, l, r):
            if len(res) == n*2:
                res.append(''.join(res))
                return
            if l<n:
                res.append('(')
                func(res, l+1, r)
                res.pop()
            if l>r:
                res.append(')')
                func(res, l, r+1)
                res.pop()
            
        return res
```
#### **子集（幂集）**
```python
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        res = []
        l = len(nums)

        def func(x, temp):
            res.append(temp)
            for j in range(x+1, l):
                func(j, temp+[nums[j]])
        func(0, [])

        return res
```
#### **多数元素**
```python
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        '''
        输入：nums = [2,2,1,1,1,2,2]
        输出：2
        '''
        vote = 0
        for num in nums:
            if vote==0:
                x = num
            if num==x:
                vote +=1 
            else:
                vote -= 1

        return x
```

