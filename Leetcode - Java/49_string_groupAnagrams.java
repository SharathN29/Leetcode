// https://leetcode.com/problems/group-anagrams/

class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> anagrams = new HashMap<String, List<String>>();
        for(String s : strs) {
            char[] charArr = s.toCharArray();
            Arrays.sort(charArr);
            String key = String.valueOf(charArr);
            if(!anagrams.containsKey(key))
                anagrams.put(key, new ArrayList<String>());
            anagrams.get(key).add(s);
        }
        return new ArrayList(anagrams.values());
    }
}