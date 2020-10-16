// https://leetcode.com/problems/cheapest-flights-within-k-stops/

class Solution {
    
    private int[][] adjMatrix; 
    private HashMap<Pair<Integer, Integer>, Long> memo;
    
    public int findCheapestPrice(int n, int[][] flights, int src, int dst, int K) {
        this.adjMatrix = new int[n][n];
        this.memo = new HashMap<Pair<Integer, Integer>, Long>();
        
        for (int[] flight : flights) {
            this.adjMatrix[flight[0]][flight[1]] = flight[2];
        }
        
        long ans = this.findShortest(src, K, dst, n);
        return ans >= Integer.MAX_VALUE ? -1 : (int)ans;
    }
    
    public long findShortest(int node, int stops, int dst, int n) {
        if(node == dst) {
            return 0;
        }
        if(stops < 0) {
            return Integer.MAX_VALUE;
        }
        
        Pair<Integer, Integer> key = new Pair<Integer, Integer>(node,stops);
        if(this.memo.containsKey(key)) {
            return this.memo.get(key);
        }
        
        long ans = Integer.MAX_VALUE;
        for (int neighbor = 0; neighbor < n; ++neighbor) {
            int weight = this.adjMatrix[node][neighbor];
            if (weight > 0) {
                ans = Math.min(ans, this.findShortest(neighbor, stops - 1, dst, n) + weight);
            }  
        } 
        
        this.memo.put(key, ans);
        return ans;
    }
}