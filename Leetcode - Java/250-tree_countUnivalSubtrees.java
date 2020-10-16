// https://leetcode.com/problems/count-univalue-subtrees/

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
    int count = 0;
    public int countUnivalSubtrees(TreeNode root) {
        if (root == null) return 0; 
        isUnivalued(root);
        return count;
    }
    
    boolean isUnivalued(TreeNode node) {
        if (node.left == null && node.right == null) {
            count++;
            return true;
        }
        
        boolean isUnival = true; 
        
        if (node.left != null) {
            isUnival = isUnivalued(node.left) && isUnival && node.left.val == node.val;
        }
        
        if (node.right != null) {
            isUnival = isUnivalued(node.right) && isUnival && node.right.val == node.val;
        }
        
        if(!isUnival) return false; 
        count++;
        return true; 
    }
}