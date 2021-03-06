// https://leetcode.com/problems/find-the-town-judge/

class Solution {
    public int findJudge(int N, int[][] trust) {
        if(trust.length < N-1) return -1; 
        
        int[] trustScore = new int[N+1];
        
        for(int[] con : trust) {
            trustScore[con[0]]--;
            trustScore[con[1]]++;
        }
        
        for(int i = 1; i <= N; i++) {
            if(trustScore[i] == N-1)
                return i;
        }
        return -1;
    }
}