"""
Course Schedule : https://leetcode.com/problems/course-schedule/
Author : Sharath Nagendra 

Passes all leetcode test cases as of Oct 8 2019
Runtime: 72 ms, faster than 96.54% of Python online submissions for Course Schedule.
Memory Usage: 13.1 MB, less than 96.61% of Python online submissions for Course Schedule.
"""
class Solution(object):
    def canFinish(self, numCourses, prerequisites):
        G = [[] for i in range(numCourses)]
        degree = [0] * numCourses
        for j,i in prerequisites:
            G[i].append(j)
            degree[j] += 1
        bfs = [i for i in range(numCourses) if degree[i] == 0]
        for i in bfs:
            for j in G[i]:
                degree[j] -= 1
                if degree[j] == 0:
                    bfs.append(j)
        return len(bfs) == numCourses

numCourses, prerequisites = 5, [[1,0], [2,1], [4,3]]
courses = Solution()
print(courses.canFinish(numCourses, prerequisites))