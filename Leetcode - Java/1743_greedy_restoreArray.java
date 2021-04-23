// https://leetcode.com/problems/restore-the-array-from-adjacent-pairs/

class Solution {
    
    Map<Integer, List> graph = new HashMap();
    Set<Integer> seenSet = new HashSet();
    List<Integer> ansList = new ArrayList();
    
    public int[] restoreArray(int[][] adjacentPairs) {
        int n = adjacentPairs.length; 
        int[] res = new int[n+1];
      
        for (int[] pair : adjacentPairs) {
            graph.computeIfAbsent(pair[0], l -> new ArrayList()).add(pair[1]);
            graph.computeIfAbsent(pair[1], s -> new ArrayList()).add(pair[0]);
        }
        
        int startNode = 0;
        for (int nodes : graph.keySet()) {
            if (graph.get(nodes).size() == 1) {
                startNode = nodes;
                break;
            }
        }
        dfs(startNode);
        
        for (int i = 0; i < ansList.size(); i++) {
            res[i] = ansList.get(i);
        }
        
        return res;
    }
    
    public void dfs(int start) {
        seenSet.add(start);
        ansList.add(start);
        
        List<Integer> neighbours = graph.get(start);
        for (Integer node : neighbours) {
            if (!seenSet.contains(node)) {
                dfs(node);
            }
        }
    }
}