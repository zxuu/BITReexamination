'''
给你两个单链表的头节点 headA 和 headB ，请你找出并返回两个单链表相交的起始节点。如果两个链表不存在相交节点，返回 null 。
'''
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        pa, pb = headA, headB
        lenA, lenB = 0, 0
        while pa:
            lenA += 1
            pa = pa.next
        while pb:
            lenB += 1
            pb = pb.next
        if lenA>=lenB:
            long = headA
            short = headB
            distance = lenA-lenB
        else:
            long = headB
            short = headA
            distance = lenB-lenA
        while distance:
            long = long.next
            distance -= 1
        
        while long and short:
            if not long:
                break
            if long==short:
                return long
            long = long.next
            short = short.next
        
        return None
