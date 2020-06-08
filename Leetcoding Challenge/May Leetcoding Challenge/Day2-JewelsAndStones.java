// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3317/

class Solution {
    public int numJewelsInStones(String J, String S) {
        int res = 0;
        Set<Character> jewels = new HashSet<Character>();
        for(int i = 0; i < J.length(); i++) {
            jewels.add(J.charAt(i));
        }
        
        for(int j = 0; j < S.length(); j++) {
            if(jewels.contains(S.charAt(j)))
                res++;
        }
        
        return res; 
    }
}