// https://leetcode.com/problems/even-odd-tree/

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
    public boolean isEvenOddTree(TreeNode root) {
        Queue<TreeNode> q = new LinkedList();
        q.add(root);
        boolean level = true;
        
        while (!q.isEmpty()) {
            int size = q.size();
            int prev = level ? Integer.MIN_VALUE : Integer.MAX_VALUE;;
            for (int i = 0; i < size; i++) {
                TreeNode curr = q.poll();
                if (level && (curr.val % 2 == 0 || (i > 0 && prev >= curr.val))) return false;
                if (!level && (curr.val % 2 != 0 || (i > 0 && prev <= curr.val))) return false;
                prev = curr.val;
                if (curr.left != null) q.add(curr.left);
                if (curr.right != null) q.add(curr.right);
            }
            level = !level;
        }
        return true;
    }
}