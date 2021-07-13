# https://leetcode.com/problems/longest-palindromic-substring/

class Solution:
    longestPal, lengthOfLongestPalindrome = "", 0

    def longest_palindrome(self, s: str) -> str:
        if len(s) < 2:
            return s

        for i in range(len(s)):
            self.check_palindrome(s, i, i)
            self.check_palindrome(s, i, i + 1)

        return self.longestPal

    def check_palindrome(self, s: str, left: int, right: int) -> None:
        while left >= 0 and right < len(s) and s[left] == s[right]:
            left -= 1
            right += 1

        if right - left - 1 > self.lengthOfLongestPalindrome:
            self.lengthOfLongestPalindrome = right - left - 1
            self.longestPal = s[left + 1: right]


def main() -> None:
    sol = Solution()
    s = "babad"
    print(sol.longestPal)


if __name__ == 'main':
    main()
