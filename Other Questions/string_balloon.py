"""
Maximum number of balloons : https://leetcode.com/problems/maximum-number-of-balloons/
Author: Sharath Nagendra

Passes all the leetcode test cases as on Sept 18 2019
Runtime: 20 ms, faster than 83.05% of Python online submissions for Maximum Number of Balloons.
Memory Usage: 11.8 MB, less than 100.00% of Python online submissions for Maximum Number of Balloons.
"""
def maxNumberOfBalloons(text):
	count = 0
	text = text.lower()
	count_b = text.count('b')
	count_a = text.count('a')
	count_l = text.count('l')
	count_o = text.count('o')
	count_n = text.count('n')
	while count_b > 0 and count_a > 0 and count_l > 1 and count_o > 1 and count_n > 0:
		count += 1
		count_b -= 1
		count_a -= 1
		count_l -= 2
		count_o -= 2
		count_n -= 1
	return count 

text = "loonbalxballpoon"
print(maxNumberOfBalloons(text))