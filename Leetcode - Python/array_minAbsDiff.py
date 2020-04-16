"""
Minimum absolute difference : https://leetcode.com/contest/weekly-contest-155/problems/minimum-absolute-difference/ 
Author : Sharath Nagendra

Passess all leetcode test cases as on Sept 27 2019
"""

def minimumAbsDifference(arr):
    n = len(arr)
    if n < 1: return []
    arr.sort()
    minDiff = float("inf")
    ansPair = []

    for i in range(1,n):
        currDiff = arr[i] - arr[i-1]
        currPair = [arr[i-1], arr[i]]

        if currDiff < minDiff:
            minDiff = currDiff
            ansPair = [currPair]

        elif currDiff == minDiff:
            ansPair.append(currPair)
    return ansPair

arr = [3,8,-10,23,19,-4,-14,27]
print(minimumAbsDifference(arr))