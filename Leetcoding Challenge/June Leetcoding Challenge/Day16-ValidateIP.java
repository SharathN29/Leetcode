// https://leetcode.com/explore/challenge/card/june-leetcoding-challenge/541/week-3-june-15th-june-21st/3362/

class Solution {
    public String validIPAddress(String IP) {
        String[] ipv4 = IP.split("\\.",-1);
        String[] ipv6 = IP.split("\\:", -1);

        if(IP.chars().filter(ch -> ch == '.').count() == 3) {
            for(String s : ipv4) {
                if(isIPv4(s)) continue; 
                else return "Neither";
            }
            return "IPv4";
        }

        if(IP.chars().filter(ch -> ch == ':').count() == 7) {
            for(String s : ipv6) {
                if(isIPv6(s)) continue; 
                else return "Neither";
            }
            return "IPv6";
        }
        return "Neither";
    }

    public static boolean isIPv4(String s) {
        try {
            return String.valueOf(Integer.valueOf(s)).equals(s) && Integer.parseInt(s) >= 0 && Integer.parseInt(s) <= 255;
        } catch (NumberFormatException e) {
            return false; 
        }
    }

    public static boolean isIPv6(String s) {
        if(s.length() > 4) return false; 
        try {
            return Integer.parseInt(s, 16) >= 0 && s.charAt(0) != '-';
        } catch (NumberFormatException e) {
            return false; 
        }
    }
}