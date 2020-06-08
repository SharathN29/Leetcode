// https://leetcode.com/explore/challenge/card/30-day-leetcoding-challenge/529/week-2/3293/

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
    int ans;
    public int diameterOfBinaryTree(TreeNode root) {
        ans = 1;
        depth(root);
        return ans-1; 
    }
    
    private int depth(TreeNode root) {
        if(root == null) return 0; 
        int l = depth(root.left);
        int r = depth(root.right);
        ans = Math.max(ans, l+r+1);
        return Math.max(l, r) + 1;
    }
}