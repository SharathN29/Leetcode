// https://leetcode.com/problems/count-and-say/

import java.util.regex.Matcher;
import java.util.regex.Pattern;

class Solution {
    public String countAndSay(int n) {
        String curr_seq = "1";
        
        String regex_pattern = "(.)\\1*";
        Pattern pattern = Pattern.compile(regex_pattern);
        
        for(int i = 1; i < n; i++) {
            Matcher m = pattern.matcher(curr_seq);
            StringBuffer next_seq = new StringBuffer();
            
            while(m.find()) {
                next_seq.append(m.group().length() + String.valueOf(m.group().charAt(0)));
            }
            
            curr_seq = next_seq.toString();
        }
        return curr_seq;
    }
}