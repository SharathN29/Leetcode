// https://leetcode.com/problems/construct-string-from-binary-tree/

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
    public String tree2str(TreeNode t) {
        if (t == null) return "";
        StringBuilder sb = new StringBuilder();
        sb.append(String.valueOf(t.val));
        if (t.left != null) {
            sb.append("(" + tree2str(t.left) + ")");
        } else if (t.right != null) sb.append("()");
        if (t.right != null) sb.append("(" + tree2str(t.right) + ")");
        return sb.toString();
    }
}