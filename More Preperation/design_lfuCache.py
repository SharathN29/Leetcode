"""
LFU Cache : https://leetcode.com/problems/lfu-cache/
Author : Sharath Nagendra 

Passes all leetcode test cases as of Oct 14 2019
"""
import collections 

class Node:
	def __init__(self, key, val):
		self.key = key
		self.val = val
		self.freq = 1
		self.prev = self.next = None

class DLinkedList:
	def __init__(self):
		self._sentinel = Node(None, None)
		self._sentinel.next = self._sentinel.prev = self._sentinel
		self._size = 0

	def __len__(self):
		return self._size

	def append(self, node):
		node.next = self._sentinel.next
		node.prev = self._sentinel
		node.next.prev = node
		self._sentinel.next = node
		self._size += 1

	def pop(self, node = None):
		if self._size == 0:
			return
		if not node:
			return self._sentinel.prev

		node.prev.next = node.next
		node.next.prev = node.prev
		self._size -= 1
		return node

	