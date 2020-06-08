// https://leetcode.com/problems/complement-of-base-10-integer/

class Solution {
    public int bitwiseComplement(int N) {
        String binaryRep = Integer.toBinaryString(N);
        StringBuilder res = new StringBuilder();

        for(char c : binaryRep.toCharArray()) {
            if(c == '1')
                res.append("0");
            else res.append("1");
        }
        
        return Integer.parseInt(res.toString(), 2);
    }
}