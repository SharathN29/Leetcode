// https://leetcode.com/problems/find-anagram-mappings/

class Solution {
    public int[] anagramMappings(int[] A, int[] B) {
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        for(int i = 0; i < B.length; i++) {
            map.put(B[i], i);
        }
        int[] p = new int[A.length];
        
        for(int i = 0; i < A.length; i++) {
            p[i] = map.get(A[i]);
        }
        
        return p;
    }
}