// https://leetcode.com/problems/find-nearest-right-node-in-binary-tree/

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
    public TreeNode findNearestRightNode(TreeNode root, TreeNode u) {
        if (root == null) return null;
        
        Queue<TreeNode> q = new LinkedList();
        TreeNode curr = null;
        q.offer(root);
        q.offer(null);
        
        while (!q.isEmpty()) {
            curr = q.poll();
            
            if (curr != null) {
                if (curr == u) return q.poll();
                if (curr.left != null) q.offer(curr.left);
                if (curr.right != null) q.offer(curr.right);
            } else {
                if (!q.isEmpty()) q.offer(null);
            }
        }
        return null;
    }
}