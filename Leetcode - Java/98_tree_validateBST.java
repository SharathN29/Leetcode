// https://leetcode.com/problems/validate-binary-search-tree/

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
    public boolean isValidBST(TreeNode root) {
        return isValidBST(root, null, null);
    }

    private boolean isValidBST(TreeNode node, TreeNode min_node, TreeNode max_node) {
        if(node == null) return true; 
        if(min_node != null && node.val <= min_node.val || max_node != null && node.val >= max_node.val) {
            return false; 
        }
        return isValidBST(node.left, min_node, node) && isValidBST(node.right, node, max_node);
    }
}