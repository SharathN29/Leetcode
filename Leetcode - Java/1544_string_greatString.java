// https://leetcode.com/problems/make-the-string-great/

class Solution {
    public String makeGood(String s) {
        Stack<Character> stack = new Stack();
        
        for (char c : s.toCharArray()) {
            if (!stack.empty() && Math.abs(stack.peek() - c) == 32) stack.pop(); 
            else stack.push(c);
        }
        
        char[] res = new char[stack.size()];
        int index = stack.size() - 1;
        while (!stack.empty()) {
            res[index--] = stack.pop();
        }
        return new String(res);
    }
}