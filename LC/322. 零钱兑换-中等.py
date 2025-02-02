'''
给你一个整数数组 coins ，表示不同面额的硬币；以及一个整数 amount ，表示总金额。

计算并返回可以凑成总金额所需的 最少的硬币个数 。如果没有任何一种硬币组合能组成总金额，返回 -1 。

你可以认为每种硬币的数量是无限的。

 

示例 1：

输入：coins = [1, 2, 5], amount = 11
输出：3 
解释：11 = 5 + 5 + 1
示例 2：

输入：coins = [2], amount = 3
输出：-1
示例 3：

输入：coins = [1], amount = 0
输出：0
 

提示：

1 <= coins.length <= 12
1 <= coins[i] <= 2^31 - 1
0 <= amount <= 10^4
'''
from typing import List
class Solution:
    def coinChange(self, coins: List[int], amount: int) -> int:
        coins.sort(reverse=True)
        min_sum = []
        def func(coins, cout, deep):
            if len(min_sum)>1:
                return
            if cout == amount:
                min_sum.append(deep)
                return
            if cout > amount:
                return
            for i in range(len(coins)):
                func(coins, cout+coins[i], deep+1)
        
        func(coins, 0, 0)
        return min(min_sum)

if __name__=="__main__":
    re = Solution().coinChange([1, 2, 5], 11)
    print(re)