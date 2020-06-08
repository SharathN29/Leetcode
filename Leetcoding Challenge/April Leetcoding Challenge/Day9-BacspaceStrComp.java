// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3291/

class Solution {
    public boolean backspaceCompare(String S, String T) {
        Stack<Character> s1 = new Stack<>();
        Stack<Character> s2 = new Stack<>();
        
        for(int i = 0; i < S.length(); i++) {
            if(S.charAt(i) == '#' && !s1.empty()) {
                s1.pop();
            } else if(S.charAt(i) != '#') {
                s1.push(S.charAt(i));
            } else {
                continue; 
            }
        }
        
        for(int i = 0; i < T.length(); i++) {
            if(T.charAt(i) == '#' && !s2.empty()) {
                s2.pop();
            } else if(T.charAt(i) != '#') {
                s2.push(T.charAt(i));
            } else {
                continue; 
            }
        }
        
        return s1.equals(s2);
    }
}