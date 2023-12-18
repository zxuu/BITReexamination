class Solution:
    def majorityElement(self, nums):
        vote = 0
        x = nums[0]
        for num in nums:
            if vote==0:
                x = num
            if x==num:
                vote += 1
            else:
                vote -= 1

        return x
class Solution8:
    def generateParenthesis(self, n):
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
if __name__ == '__main__':
    result = Solution8().generateParenthesis(3)
    print(result)