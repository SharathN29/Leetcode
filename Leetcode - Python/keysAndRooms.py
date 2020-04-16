"""
Keys And Rooms : https://leetcode.com/problems/keys-and-rooms/
Author: Sharath Nagendra
This code pases all Leetcode test cases as on Sept 12, 2019. 

"""

def canVisitAllRooms(rooms): 
	dfs = [0]
	seen = set(dfs)
	while dfs:
		i = dfs.pop()
		for j in rooms[i]:
			if j not in seen:
				dfs.append(j)
				seen.add(j)
				if len(seen) == len(rooms): return True
	return len(seen) == len(rooms)

rooms = [[1,3],[3,0,1],[2],[0]]
print(canVisitAllRooms(rooms))