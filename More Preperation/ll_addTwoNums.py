"""
Add Two Numbers : https://leetcode.com/problems/add-two-numbers/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 15 2019
Runtime: 52 ms, faster than 82.18% of Python online submissions for Add Two Numbers.
Memory Usage: 11.8 MB, less than 62.50% of Python online submissions for Add Two Numbers.
"""
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def addTwoNumbers(self, l1, l2):
    	dummy = cur = ListNode(0)
    	carry = 0
    	while l1 or l2 or carry:
    		if l1:
    			carry += l1.val
    			l1 = l1.next
    		if l2:
    			carry += l2.val
    			l2 = l2.next
    		cur.next = ListNode(carry%10)
    		cur = cur.next
    		carry //= 10
    	return dummy.next