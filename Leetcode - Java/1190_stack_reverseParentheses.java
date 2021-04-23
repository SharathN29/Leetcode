// https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/

class Solution {
//     public String reverseParentheses(String s) {
//         int n = s.length();
//         Stack<Integer> stack = new Stack();
//         int[] pair = new int[n];
        
//         for (int i = 0; i < n; i++) {
//             if (s.charAt(i) == '(') {
//                 stack.push(i);
//             }  
//             if (s.charAt(i) == ')') {
//                 int j = stack.pop();
//                 pair[i] = j;
//                 pair[j] = i;
//             }
//         }
        
//         StringBuilder sb = new StringBuilder();
//         for (int i = 0, d = 1; i < n; i += d) {
//             if (s.charAt(i) == '(' || s.charAt(i) == ')') {
//                 i = pair[i];
//                 d = -d;
//             } else {
//                 sb.append(s.charAt(i));
//             }
//         }
//         return sb.toString();
//     }
    
    public String reverseParentheses(String s) {
        Stack<Character> st = new Stack();
        for (char c : s.toCharArray()) {
            if (c == ')') {
                Queue<Character> q = new LinkedList();
                while (!st.empty() && st.peek() != '(') q.offer(st.pop());
                if (!st.empty()) st.pop();
                while (!q.isEmpty()) st.push(q.remove());
            } else {
                st.push(c);
            }
        }
        
        StringBuilder sb = new StringBuilder();
        while (!st.empty()) {
            sb.append(st.pop());
        }
        return sb.reverse().toString();
    }
}