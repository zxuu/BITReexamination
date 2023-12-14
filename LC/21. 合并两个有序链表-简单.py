'''
将两个升序链表合并为一个新的 升序 链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。 

 

示例 1：


输入：l1 = [1,2,4], l2 = [1,3,4]
输出：[1,1,2,3,4,4]
示例 2：

输入：l1 = [], l2 = []
输出：[]
示例 3：

输入：l1 = [], l2 = [0]
输出：[0]
 

提示：

两个链表的节点数目范围是 [0, 50]
-100 <= Node.val <= 100
l1 和 l2 均按 非递减顺序 排列
'''
# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next
from typing import List
class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        l3 = ListNode(0)
        l3_pre = l3
        while list1!=None and list2!=None:
            if list1.val <= list2.val:
                # 断l1的链
                temp = list1.next
                list1.next = None
                # 拼接到l3
                l3_pre.next = list1
                l3_pre = l3_pre.next
                list1 = temp
            else:
                # 断l2的链
                temp = list2.next
                list2.next = None
                # 拼接到l3
                l3_pre.next = list2
                l3_pre = l3_pre.next
                list2 = temp
        while list1:
            temp = list1.next
            list1.next = None
            # 拼接到l3
            l3_pre.next = list1
            l3_pre = l3_pre.next
            list1 = temp
        while list2:
            # 断l2的链
            temp = list2.next
            list2.next = None
            # 拼接到l3
            l3_pre.next = list2
            l3_pre = l3_pre.next
            list2 = temp
        
        return l3