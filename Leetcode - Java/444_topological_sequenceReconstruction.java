// https://leetcode.com/problems/sequence-reconstruction/

class Solution {
    public boolean sequenceReconstruction(int[] org, List<List<Integer>> seqs) {
        List<Integer> sortedOrder = new ArrayList();
        if (org.length <= 0) {
            return false;
        }
        
        Map<Integer, Integer> indegree = new HashMap();
        Map<Integer, List> graph = new HashMap();
        
        for (List<Integer> seq : seqs) {
            for (int i : seq) {
                indegree.putIfAbsent(i, 0);
                graph.putIfAbsent(i, new ArrayList());
            }
        }
        
        for (List<Integer> seq : seqs) {
            for (int i = 0; i < seq.size() - 1; i++) {
                int parent = seq.get(i), child = seq.get(i + 1);
                indegree.put(child, indegree.get(child) + 1);
                graph.get(parent).add(child);
            }
        }
        
        if (indegree.size() != org.length) {
            return false;
        }
        
        Queue<Integer> sources = new LinkedList();
        for (Map.Entry<Integer, Integer> entry : indegree.entrySet()) {
            if (entry.getValue() == 0) {
                sources.offer(entry.getKey());
            }
        }
        
        while (!sources.isEmpty()) {
            if (sources.size() > 1) {
                return false;
            }
            
            if (org[sortedOrder.size()] != sources.peek()) {
                return false;
            }
            
            int vertex = sources.poll();
            sortedOrder.add(vertex);
            List<Integer> children = graph.get(vertex);
            for (int c : children) {
                indegree.put(c, indegree.get(c) - 1);
                if (indegree.get(c) == 0) {
                    sources.offer(c);
                }
            }
        }
        
        return sortedOrder.size() == org.length;
    }
}