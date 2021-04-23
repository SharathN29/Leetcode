// https://leetcode.com/problems/maximum-average-subtree/

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
    private double res = 0;
    
    public double maximumAverageSubtree(TreeNode root) {
        calcAve(root);
        return res;
    }
    
    private double[] calcAve(TreeNode root) {
        if (root == null) {
            return new double[]{0, 0.0};
        }
        double[] l = calcAve(root.left), r = calcAve(root.right);
        double sum = l[0] + r[0] + root.val;
        double n = l[1] + r[1] + 1;
        
        res = Math.max(res, sum/n);
        return new double[]{sum,n};
    }
}