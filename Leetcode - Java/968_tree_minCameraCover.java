// https://leetcode.com/problems/binary-tree-cameras/

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
    int res;
    Set<TreeNode> covered; 
    
    public int minCameraCover(TreeNode root) {
        res = 0;
        covered = new HashSet();
        covered.add(null);
        
        dfs(root, null);
        return res;
    }
    
    private void dfs(TreeNode node, TreeNode parent) {
        if (node != null) {
            dfs(node.left, node);
            dfs(node.right, node);
            
            if ((parent == null && !covered.contains(node)) 
            || !covered.contains(node.left) || !covered.contains(node.right)) {
                res++;
                covered.add(node);
                covered.add(parent);
                covered.add(node.left);
                covered.add(node.right);
            }
        }
    }
}