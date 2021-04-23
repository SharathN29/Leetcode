// https://leetcode.com/problems/course-schedule-iv/

class Solution {
    public List<Boolean> checkIfPrerequisite(int n, int[][] prerequisites, int[][] queries) {
        int[] indegree = new int[n];
        Map<Integer, Set> adj = new HashMap();
        Map<Integer, Set> prereqMap = new HashMap();
        
        for (int i = 0; i < n; i++) {
            adj.put(i, new HashSet());
            prereqMap.put(i, new HashSet());
        }
        
        for (int[] pre : prerequisites) {
            adj.get(pre[0]).add(pre[1]);
            indegree[pre[1]]++;
        }
        
        Queue<Integer> origin = new LinkedList();
        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                origin.offer(i);
            }
        }
        
        while (!origin.isEmpty()) {
            int node = origin.poll();
            Set<Integer> set = adj.get(node);
            for (int next : set) {
                prereqMap.get(next).add(node);
                prereqMap.get(next).addAll(prereqMap.get(node));
                if (--indegree[next] == 0) {
                    origin.offer(next);
                }
            }
        }
        
        List<Boolean> res = new ArrayList();
        for (int[] pair : queries) {
            Set<Integer> set = prereqMap.get(pair[1]);
            if (set.contains(pair[0])) {
                res.add(true);
            } else {
                res.add(false);
            }
        }
        
        return res;
    }
}