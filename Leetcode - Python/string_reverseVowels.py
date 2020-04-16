"""
Reverse Vowels of a String: https://leetcode.com/problems/reverse-vowels-of-a-string/
Author: Sharath Nagendra

Passes all the leetcode test cases as on Sept 17, 2019.
Runtime: 44 ms, faster than 80.88% of Python online submissions for Reverse Vowels of a String.
Memory Usage: 13.9 MB, less than 69.23% of Python online submissions for Reverse Vowels of a String.
"""

def reverseVowels(s):
	vowels = "aeiouAEIOU"
	s = list(s)
	i, j = 0, len(s) - 1
	while i < j:
		while s[i] not in vowels and i < j:
			i += 1
		while s[j] not in vowels and i < j:
			j -= 1
		s[i], s[j] = s[j], s[i]
		i, j = i+1, j-1
	return ''.join(s)

s = "leetcode"
print(reverseVowels(s))