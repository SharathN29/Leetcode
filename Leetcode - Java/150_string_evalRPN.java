// https://leetcode.com/problems/evaluate-reverse-polish-notation/

class Solution {
    public int evalRPN(String[] tokens) {
        Deque<Integer> stack = new LinkedList();
        
        for (String s : tokens) {
            if (s.equals("+")) {
                int b = stack.removeFirst();
                int a = stack.removeFirst();
                
                stack.push(a + b);
            } else if (s.equals("-")) {
                int b = stack.removeFirst();
                int a = stack.removeFirst();
                
                stack.push(a - b);
            } else if (s.equals("*")) {
                int b = stack.removeFirst();
                int a = stack.removeFirst();
                
                stack.push(a * b);
            } else if (s.equals("/")) {
                int b = stack.removeFirst();
                int a = stack.removeFirst();
                
                stack.push(a / b);
            } else {
                stack.addFirst(Integer.parseInt(s));
            }
        }
        
        return stack.removeFirst();
    }
}