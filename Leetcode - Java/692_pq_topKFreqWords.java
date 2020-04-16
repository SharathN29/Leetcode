// https://leetcode.com/problems/top-k-frequent-words/

class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String, Integer> map = new HashMap<>();
        for(String word : words) 
            map.put(word, map.getOrDefault(word, 0)+1);
        
        PriorityQueue<Map.Entry<String, Integer>> pq = new PriorityQueue<>(((a,b) -> a.getValue()==b.getValue() ? a.getKey().compareTo(b.getKey()) : b.getValue()-a.getValue());
        for(Map.Entry<String, Integer> entry : map.entrySet())
            pq.add(entry);
        
        List<String> res = new ArrayList<>();
        while(res.size() < k) {
            Map.Entry<String, Integer> entry = pq.poll();
            res.add(entry.getKey());
        }
        
        return res;
    }
}