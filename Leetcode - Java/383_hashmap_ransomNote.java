// https://leetcode.com/problems/ransom-note/

 class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        if(ransomNote.length() > magazine.length())
            return false; 
        
        Map<Character, Integer> magazineCounts = makeCountsMap(magazine);
        
        for(char c : ransomNote.toCharArray()) {
            int countInMagazine = magazineCounts.getOrDefault(c, 0);
            if(countInMagazine == 0) 
                return false; 
            magazineCounts.put(c, countInMagazine-1);
        }
        return true; 
    }
    
    private Map<Character, Integer> makeCountsMap(String s) {
        Map<Character, Integer> counts = new HashMap<>();
        for(char c : s.toCharArray()) {
            int currentCount = counts.getOrDefault(c, 0);
            counts.put(c, currentCount+1);
        }
        return counts; 
    }
}