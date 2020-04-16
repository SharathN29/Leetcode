// https://leetcode.com/problems/defanging-an-ip-address/

class Solution {
    public String defangIPaddr(String address) {
        StringBuffer sb = new StringBuffer(address.length());
        for(int i = 0; i < address.length(); i++) {
            if(address.charAt(i) == '.') {
                sb.append("[.]");
            } else sb.append(address.charAt(i));
        }
        return sb.toString();
    }
}

