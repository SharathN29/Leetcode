// https://leetcode.com/explore/challenge/card/may-leetcoding-challenge/534/week-1-may-1st-may-7th/3322/

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
    
    TreeNode xParent = null, yParent = null;
    int xDepth = -1, yDepth = -1;
    
    public boolean isCousins(TreeNode root, int x, int y) {
        getDepthAndParents(root, x, y, 0, null);
        return xDepth == yDepth && xParent != yParent;
    }
    
    private void getDepthAndParents(TreeNode node, int x, int y, int depth, TreeNode parent) {
        if(node == null) {
            return;
        }
        
        if(node.val == x) {

            xParent = parent;
            xDepth = depth;

        } else if(node.val == y) {

            yParent = parent; 
            yDepth = depth;

        } else {

            getDepthAndParents(node.left, x, y, depth+1, node);
            getDepthAndParents(node.right, x, y, depth+1, node);
            
        }
    }
}