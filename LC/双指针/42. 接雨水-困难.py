'''
给定 n 个非负整数表示每个宽度为 1 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。

示例 1：

输入：height = [0,1,0,2,1,0,1,3,2,1,2,1]
输出：6
解释：上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6 个单位的雨水（蓝色部分表示雨水）。 
示例 2：

输入：height = [4,2,0,3,2,5]
输出：9

提示：

n == height.length
1 <= n <= 2 * 10^4
0 <= height[i] <= 10^5
'''
class Solution:
    def trap(self, height):
        """
        官方
        :type height: List[int]
        :rtype: int
        """
        result = 0    # 记录能接到的雨水量
        left, right = 0, len(height) - 1    # 左右双指针
        leftMax = rightMax = 0    # 记录双指针见到过的最大值

        while left < right:
            leftMax = max(leftMax, height[left])     # 先记录最大值
            rightMax = max(rightMax, height[right])
            if height[left] < height[right]:    # 这是条件，有右边的大的墙挡着才能接到水
                result += leftMax - height[left]     # 当前的差值，就是当前位置可接到的水量
                left += 1     # 左指针加加
            else:
                result += rightMax - height[right]
                right -= 1
        # 注意：哪一边的某一列比较大就会一直和这列比较
        return result
class Copy():
    def trap(self, height):
        """
        copy 官方
        :type height: List[int]
        :rtype: int
        """
        result = 0     # 盛水量
        left, right = 0, len(height)-1
        maxleft, maxright = 0, 0

        while left<right:
            maxleft = max(maxleft, height[left])
            maxright = max(maxright, height[right])

            if height[left] < height[right]:
                result += maxleft - height[left]
                left += 1
            else:
                result += maxright - height[right]
                right -= 1
        return result
if __name__ == '__main__':
    re = Copy().trap([3,2,1,2,1])
    print(re)