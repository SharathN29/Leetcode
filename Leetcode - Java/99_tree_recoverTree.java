// https://leetcode.com/problems/recover-binary-search-tree/

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
    TreeNode firstElem = null;
    TreeNode secondElem = null;
    TreeNode prevElem = new TreeNode(Integer.MIN_VALUE);
    
    public void recoverTree(TreeNode root) {
        traverse(root);
        int temp = firstElem.val;
        firstElem.val = secondElem.val;
        secondElem.val = temp;
    }
    
    private void traverse(TreeNode root) {
        if (root == null) return;
        traverse(root.left);
        if (firstElem == null && prevElem.val > root.val) {
            firstElem = prevElem;
        }
        if (firstElem != null && prevElem.val > root.val) {
            secondElem = root;
        }
        prevElem = root;
        traverse(root.right);
    }
}