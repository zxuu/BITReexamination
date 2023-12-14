'''
给你单链表的头节点 head ，请你反转链表，并返回反转后的链表。
 

示例 1：


输入：head = [1,2,3,4,5]
输出：[5,4,3,2,1]
示例 2：


输入：head = [1,2]
输出：[2,1]
示例 3：

输入：head = []
输出：[]
 

提示：

链表中节点的数目范围是 [0, 5000]
-5000 <= Node.val <= 5000
 

进阶：链表可以选用迭代或递归方式完成反转。你能否用两种方法解决这道题？
'''
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head) :
        """
        pre指针
        Args:
            head (_type_): ListNode

        Returns:
            _type_: ListNode
        """
        curr, pre = head, None     # pre原先就是None，可以不是ListNode
        while(curr):
            temp = curr.next # 后继节点
            curr.next = pre    # curr引用指向前面
            pre = curr    # 
            curr = temp    # curr访问下一节点
        
        return pre


class Solution:
    def reverseList(self, head):
        '''递归
        最开始会一直往后找，一直找到最后
        '''
        def recur(pre, cur):
            # 终止条件 当前为None
            if cur == None:
                return pre
            res = recur(cur, cur.next)     # 递归（）
            cur.next = pre    # 调换指针

            return res

        return recur(None, head)
