"""
Trapping Rain Water II : https://leetcode.com/problems/trapping-rain-water-ii/
Author : Sharath Nagendra

Passes all leetcode test cases as of Oct 5, 2019
Runtime: 188 ms, faster than 53.82% of Python online submissions for Trapping Rain Water II.
Memory Usage: 13.3 MB, less than 33.33% of Python online submissions for Trapping Rain Water II.
"""
import heapq

def trapRainWater(heightMap):
    if not heightMap or not heightMap[0]:
        return 0
    heap, result = [], 0
    row, col = len(heightMap), len(heightMap[0])
    visited = [[0]*col for _ in range(row)]

    for i in range(row):
        for j in range(col):
            if (i in [0,row-1] or j in [0,col-1]):
                heapq.heappush(heap, (heightMap[i][j], i, j))
                visited[i][j] = 1

    while heap:
        height, i, j = heapq.heappop(heap)
        for x,y in ((i+1,j), (i-1,j), (i,j+1), (i,j-1)):
            if 0<=x<row and 0<=y<col and visited[x][y] == 0:
                result += max(0, height-heightMap[x][y])
                heapq.heappush(heap,(max(heightMap[x][y],height),x,y))
                visited[x][y] = 1

    return result

heightMap = [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]]
print(trapRainWater(heightMap))