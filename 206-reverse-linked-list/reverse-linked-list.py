# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def reverseList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        if(head == None):
            return None
            
        prev = None
        curr = head
        forw = head.next

        while(forw):
            curr.next = prev
            prev = curr
            curr = forw
            forw = forw.next
        
        curr.next = prev
        return curr
