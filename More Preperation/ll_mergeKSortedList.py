"""
Merge K Sorted Lists : https://leetcode.com/problems/merge-k-sorted-lists/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 16 2019
Runtime: 108 ms, faster than 48.25% of Python online submissions for Merge k Sorted Lists.
Memory Usage: 17.5 MB, less than 43.94% of Python online submissions for Merge k Sorted Lists.
"""
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
	def mergeKLists(self, lists):
		if not lists:
			return 
		if len(lists) == 1:
			return lists[0]
		mid = len(lists) // 2
		l = self.mergeKLists(lists[:mid])
		r = self.mergeKLists(lists[mid:])
		return self.merge(l, r)

	def merge(self, l, r):
		dummy = cur = ListNode(0)
		while l and r:
			if l.val < r.val:
				cur.next = l
				l = l.next
			else:
				cur.next = r
				r = r.next
			cur = cur.next
		cur.next = l or r
		return dummy.next