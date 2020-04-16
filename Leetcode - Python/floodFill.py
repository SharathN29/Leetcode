"""
Flood Fill : https://leetcode.com/problems/flood-fill/
Author: Sharath Nagendra

Passes all the leetcode test cases as on Sept 12 2019.
Runtime: 52 ms, faster than 98.18% of Python online submissions for Flood Fill.
Memory Usage: 12.1 MB, less than 18.18% of Python online submissions for Flood Fill.
"""

def floodFill(image, sr, sc, newColor):
	R, C = len(image), len(image[0])
	color = image[sr][sc]
	if color == newColor: return image
	def dfs(r,c):
		if image[r][c] == color:
			image[r][c] = newColor
			if r >= 1: dfs(r-1, c)
			if r+1 < R: dfs(r+1, c)
			if c >= 1: dfs(r, c-1)
			if c+1 < C: dfs(r, c+1)
	dfs(sr, sc)
	return image

image = [[1,1,1], [1,1,0],[1,0,1]]
print(floodFill(image, 1, 1, 2))