// https://leetcode.com/problems/top-k-frequent-elements/

class Solution {
	public List<Integer> topKFrequent(int[] nums, int k) {
		Map<Integer, Integer> map = new HashMap<>();
		for(int n : nums) 
			map.put(n, map.getOrDefault(n, 0)+1);

		PriorityQueue<Map.Entry<Integer, Integer>> pq = new PriorityQueue<>((a,b)->(b.getValue() - a.getValue()));
		for(Map.Entry<Integer, Integer> entry : map.entrySet()) 
			pq.add(entry);

		List<Integer> res = new ArrayList<Integer>();
		while(res.size() < k) {
			Map.Entry<Integer, Integer> entry = pq.poll();
			res.add(entry.getKey());
		}

		return res;
	}
}