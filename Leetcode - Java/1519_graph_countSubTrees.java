// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/

class Solution {
    public int[] countSubTrees(int n, int[][] edges, String labels) {
        Map<Integer, List<Integer>> graph = new HashMap();
        for (int[] edge : edges) {
            graph.computeIfAbsent(edge[0], l -> new ArrayList<>()).add(edge[1]);
            graph.computeIfAbsent(edge[1], l -> new ArrayList<>()).add(edge[0]);
        }
        int[] ans = new int[n];
        dfs(graph, 0, -1, labels, ans);
        return ans;
    }
    
    private int[] dfs(Map<Integer, List<Integer>> graph, int node, int parent, String labels, int[] ans) {
        int[] count = new int[26];
        char c = labels.charAt(node);
        for (int child : graph.getOrDefault(node, Collections.emptyList())) {
            if (child != parent) {
                int[] sub = dfs(graph, child, node, labels, ans);
                for (int i = 0; i < 26; i++) {
                    count[i] += sub[i];
                }
            }
        }
        ++count[c - 'a'];
        ans[node] = count[c - 'a'];
        return count;
    }
}