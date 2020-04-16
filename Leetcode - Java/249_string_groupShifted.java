// https://leetcode.com/problems/group-shifted-strings/

class Solution {
    public List<List<String>> groupStrings(String[] strings) {
        Map<String, List<String>> seq = new HashMap<String, List<String>>();
        for(String s : strings) {
            String key = "";
            for(int i = 1; i < s.length(); i++) {
                int offset = s.charAt(i) - s.charAt(i-1);
                key += offset < 0 ? offset + 26 : offset; 
            }
            if(!seq.containsKey(key))
                seq.put(key, new ArrayList<String>());
            seq.get(key).add(s);
        }
        return new ArrayList(seq.values());
    }
}