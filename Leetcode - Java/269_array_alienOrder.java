// https://leetcode.com/problems/alien-dictionary/

class Solution {
    public String alienOrder(String[] words) {
        if(words == null || words.length == 0) {
            return "";
        }
        
        Map<Character, Integer> indegree = new HashMap();
        Map<Character, List<Character>> graph = new HashMap();
        
        for (String word : words) {
            for (char c : word.toCharArray()) {
                indegree.put(c, 0);
                graph.put(c, new ArrayList());
            }
        }
        
        for (int i = 0; i < words.length - 1; i++) {
            String w1 = words[i], w2 = words[i + 1];
            if (w1.length() > w2.length() && w1.startsWith(w2)) {
                return "";
            }
            for (int j = 0; j < Math.min(w1.length(), w2.length()); j++) {
                char parent = w1.charAt(j), child = w2.charAt(j);
                if (parent != child) {
                    indegree.put(child, indegree.get(child) + 1);
                    graph.get(parent).add(child);
                    break;
                }
            }
        }
        
        Queue<Character> sources = new LinkedList();
        for (Map.Entry<Character, Integer> entry : indegree.entrySet()) {
            if (entry.getValue() == 0) {
                sources.add(entry.getKey());
            }
        }
        
        StringBuilder sb = new StringBuilder();
        while (!sources.isEmpty()) {
            Character vertex = sources.poll();
            sb.append(vertex);
            List<Character> children = graph.get(vertex);
            for (Character c : children) {
                indegree.put(c, indegree.get(c) - 1);
                if (indegree.get(c) == 0) {
                    sources.add(c);
                }
            }
        }
        
        if (sb.length() != indegree.size()) {
            return "";
        }
        
        return sb.toString();
    }
}