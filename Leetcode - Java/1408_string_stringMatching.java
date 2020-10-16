// https://leetcode.com/problems/string-matching-in-an-array/

class Solution {
    public List<String> stringMatching(String[] words) {
        Arrays.sort(words, new java.util.Comparator<String>(){
            @Override
            public int compare(String s1, String s2){
                return s1.length()-s2.length();
            }
        });
        
        List<String> res = new LinkedList();
        
        for(int i = 0; i < words.length-1; i++) {
            int j = i+1; 
            while (j < words.length) {
                int index = words[j++].indexOf(words[i]);
                if (index != -1) { 
                    res.add(words[i]);
                    break;
                }
            }
        }
        return res;
    }
}