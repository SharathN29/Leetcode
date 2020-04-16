"""
Path in Zigzag labelled binary tree : https://leetcode.com/problems/path-in-zigzag-labelled-binary-tree/
Author : Sharath Nagendra

Passes all leetcode test cases as on Sept 18 2019
Runtime: 16 ms, faster than 72.96% of Python online submissions for Path In Zigzag Labelled Binary Tree.
Memory Usage: 11.8 MB, less than 100.00% of Python online submissions for Path In Zigzag Labelled Binary Tree.
"""
def pathInZigZagTree(label):
	res = []
	nodeCount = 1
	level = 1
	while label >= nodeCount * 2:
		nodeCount *= 2
		level += 1
	while label != 0:
		res.append(label)
		levelMax = 2 ** (level) - 1
		levelMin = 2 ** (level - 1)
		label = int((levelMax + levelMin - label) / 2)
		level -= 1
	return res[::-1]

print(pathInZigZagTree(24))