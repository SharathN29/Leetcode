"""
Merge two sorted list : https://leetcode.com/problems/merge-two-sorted-lists/
Author : Sharath Nagendra 

Passes all leetcode test cases as of Oct 13 2019
Runtime: 16 ms, faster than 96.74% of Python online submissions for Merge Two Sorted Lists.
Memory Usage: 11.9 MB, less than 34.48% of Python online submissions for Merge Two Sorted Lists.
"""
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def mergeTwoLists(self, l1, l2):
    	if l1 is None:
    		return l2
    	elif l2 is None:
    		return l1
    	elif l1.val < l2.val:
    		l1.next = self.mergeTwoLists(l1.next, l2)
    		return l1
    	else: 
    		l2.next = self.mergeTwoLists(l1, l2.next)
    		return l2

    def mergeTwoLists2(self, l1, l2):
    	prehead = ListNode(-1)
    	prev = prehead
    	while l1 and l2:
    		if l1.val < l2.val:
    			prev.next = l1
    			l1 = l1.next
    		else:
    			prev.next = l2
    			l2 = l2.next
    		prev = prev.next
    	prev.next = l1 or l2
    	return prehead.next