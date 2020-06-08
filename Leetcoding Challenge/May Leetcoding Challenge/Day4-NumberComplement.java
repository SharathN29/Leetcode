// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3319/

class Solution {
    public int findComplement(int num) {
        String binRep = Integer.toBinaryString(num);
        StringBuilder binComp = new StringBuilder();
        
        for(char c : binRep.toCharArray()) {
            if(c == '1') binComp.append("0");
            else binComp.append("1");
        }
        
        return Integer.parseInt(binComp.toString(), 2);
    }
}