// https://leetcode.com/problems/keys-and-rooms/

class Solution {
    public boolean canVisitAllRooms(List<List<Integer>> rooms) {
        boolean[] seen = new boolean[rooms.size()];
        seen[0] = true; 
        Stack<Integer> stack = new Stack();
        stack.push(0);
        
        while (!stack.isEmpty()) {
            int node = stack.pop();
            for (int n : rooms.get(node)) {
                if (!seen[n]) {
                    seen[n] = true; 
                    stack.push(n);
                }
            }
        }
        
        for (boolean v : seen) {
            if (!v) return false; 
        }
        
        return true; 
    }
}