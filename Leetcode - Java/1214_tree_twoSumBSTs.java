// https://leetcode.com/problems/two-sum-bsts/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public boolean twoSumBSTs(TreeNode root1, TreeNode root2, int target) {
        Deque<TreeNode> stack1 = new ArrayDeque<>();
        Deque<TreeNode> stack2 = new ArrayDeque<>();
        pushAll(stack1, root1, true);
        pushAll(stack2, root2, false);
        while (!stack1.isEmpty() && !stack2.isEmpty()) {
            int sum = stack1.peek().val + stack2.peek().val;
            if (sum > target)
                pop(stack2, false);
            else if (sum < target)
                pop(stack1, true);
            else
                return true;
        }
        return false;
    }
    
    private void pushAll(Deque<TreeNode> stack, TreeNode node, boolean isInc) {
        while (node != null) {
            stack.push(node);
            node = isInc ? node.left : node.right;
        }
    }
    
    private TreeNode pop(Deque<TreeNode> stack, boolean isInc) {
        TreeNode node = stack.pop();
        pushAll(stack, isInc ? node.right : node.left, isInc);
        return node;
    }
}