// https://leetcode.com/problems/hexspeak/

class Solution {
    public String toHexspeak(String num) {
        long n = Long.parseLong(num);
        String res = Long.toHexString(n).toUpperCase().replace('1', 'I').replace('0', 'O');
        for (char c : res.toCharArray())
            if (Character.isDigit(c))
                return "ERROR";
        return res;  
    }
}
