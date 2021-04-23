// https://leetcode.com/problems/longest-valid-parentheses/

// class Solution {
//     public int longestValidParentheses(String s) {
//         int maxLen = 0;
//         Stack<Integer> stack = new Stack();
//         stack.push(-1);
        
//         for (int i = 0; i < s.length(); i++) {
//             if (s.charAt(i) == '(') {
//                 stack.push(i);
//             } else {
//                 stack.pop();
//                 if (stack.empty()) {
//                     stack.push(i);
//                 } else {
//                     maxLen = Math.max(maxLen, i - stack.peek());
//                 }
//             }
//         }
//         return maxLen;
//     }
// }

class Solution {
    public int longestValidParentheses(String s) {
        int maxlen = 0, left = 0, right = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') left++;
            else right++;
            
            if (left == right) maxlen = Math.max(maxlen, 2 * right);
            else if (right > left) left = right = 0;
        }
        
        left = right = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            if (s.charAt(i) == '(') left++;
            else right++;
            
            if (left == right) maxlen = Math.max(maxlen, 2 * left);
            if (left > right) left = right = 0;
        }
        
        return maxlen;
    }
}