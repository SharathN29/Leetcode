# https://leetcode.com/problems/check-if-n-and-its-double-exist/

class Solution:
    def checkIfExist(self, arr: List[int]) -> bool:
        seen = set()
        for a in arr : 
            if a * 2 in seen or a / 2 in seen : 
                return True
            seen.add(a)

        return False