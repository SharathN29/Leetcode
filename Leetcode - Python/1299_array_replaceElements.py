# https://leetcode.com/problems/replace-elements-with-greatest-element-on-right-side/


class Solution:
    def replaceElements(self, arr: List[int]) -> List[int]:
        size = len(arr) - 1
        prevElem = arr[size]
        arr[size] = -1

        for i in range(size - 1, -1, -1):
            currElem = max(prevElem, arr[i + 1])
            prevElem = arr[i]
            arr[i] = currElem

        return arr
