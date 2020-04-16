// https://leetcode.com/problems/symmetric-tree/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        return isSymmetric(root, root);
    }
    
    public boolean isSymmetric(TreeNode l, TreeNode r) {
        if(l == null && r == null) return true;
        if(l == null || r == null) return false; 
        return (l.val == r.val) && isSymmetric(l.left, r.right) && isSymmetric(l.right, r.left);
    }
}