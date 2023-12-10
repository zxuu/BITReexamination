'''
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。

 

示例 1：



输入：[1,8,6,2,5,4,8,3,7]
输出：49 
解释：图中垂直线代表输入数组 [1,8,6,2,5,4,8,3,7]。在此情况下，容器能够容纳水（表示为蓝色部分）的最大值为 49。
示例 2：

输入：height = [1,1]
输出：1
 

提示：

n == height.length
2 <= n <= 10^5
0 <= height[i] <= 10^4
'''
class Solution(object):
    def maxArea(self, height):
        """
        一前一后双指针。当然那边小移动哪边
        :type height: List[int]
        :rtype: int
        """
        left, right = 0, len(height)-1
        max_v = 0
        while left < right:
            w = right - left
            h = min(height[left], height[right])
            if w*h > max_v:
                max_v = w*h
            if height[left] <= height[right]:
                left += 1
            else:
                right -= 1
        return max_v
class Solution(object):
    def maxArea(self, height):
        """
        一前一后双指针。当然那边小移动哪边.
        加快操作：移动的时候，除非比原先的高，才停止
        :type height: List[int]
        :rtype: int
        """
        left, right = 0, len(height)-1
        max_v = 0
        while left < right:
            w = right - left
            h = min(height[left], height[right])
            if w*h > max_v:
                max_v = w*h
            if height[left] <= height[right]:
                current_left = left
                while left < right and height[left] <= height[current_left]:
                    left += 1
                # left += 1
            else:
                current_right = right
                while left<right and height[right] <= height[current_right]:
                    right -= 1
                # right -= 1
        return max_v
if __name__ == '__main__':
    s = Solution().maxArea([1,8,6,2,5,4,8,3,7])
    print(s)

