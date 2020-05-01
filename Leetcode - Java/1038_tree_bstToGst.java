// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

// We need to do the work from biggest to smallest, right to left.
// pre will record the previous value the we get, which the total sum of bigger values.
// For each node, we update root.val with root.val + pre.


class Solution {
    int pre = 0;
    public TreeNode bstToGst(TreeNode root) {
        if (root.right != null) bstToGst(root.right);
        pre = root.val = pre + root.val;
        if (root.left != null) bstToGst(root.left);
        return root;
    }
}