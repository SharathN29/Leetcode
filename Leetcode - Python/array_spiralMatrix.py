"""
Spiral Matrix : https://leetcode.com/problems/spiral-matrix/
Author : Sharath Nagendra

Passes all leetcode test cases as on Sept 18 2019
Runtime: 16 ms, faster than 71.58% of Python online submissions for Spiral Matrix.
Memory Usage: 11.7 MB, less than 69.70% of Python online submissions for Spiral Matrix.
"""
def spiralOrder(matrix):
	if matrix == []:
		return matrix 

	left, right, top, bottom = 0, len(matrix[0])-1, 0, len(matrix) - 1
	res = []

	while left <= right and top <= bottom:
		for i in range(left, right+1):
			res.append(matrix[top][i])
		top += 1

		for i in range(top, bottom+1):
			res.append(matrix[i][right])
		right -= 1

		if top <= bottom:
			for i in range(right, left-1, -1):
				res.append(matrix[bottom][i])
			bottom -= 1

		if left <= right:
			for i in range(bottom, top-1, -1):
				res.append(matrix[i][left])
			left += 1

	return res 

matrix = [[1,2,3], [4,5,6], [7,8,9]]
print(spiralOrder(matrix))

