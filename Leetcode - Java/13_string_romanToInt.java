// https://leetcode.com/problems/roman-to-integer/

class Solution {
    static Map<String, Integer> values = new HashMap<>();
    
    static {
        values.put("M", 1000);
        values.put("D", 500);
        values.put("C", 100);
        values.put("L", 50);
        values.put("X", 10);
        values.put("V", 5);
        values.put("I", 1);
    }
    
    public int romanToInt(String s) {
        int sum = 0;
        int i = 0;
        
        while(i < s.length()) {
            String curr_symbol = s.substring(i, i+1);
            int curr_val = values.get(curr_symbol);
            int next_val = 0;
            
            if(i+1 < s.length()) {
                String next_symbol = s.substring(i+1, i+2);
                next_val = values. get(next_symbol);
            }
            
            if(curr_val < next_val) {
                sum += (next_val - curr_val);
                i += 2;
            } else {
                sum += curr_val; 
                i += 1;
            }
        }
        return sum;
    }
}