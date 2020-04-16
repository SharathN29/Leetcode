// https://leetcode.com/problems/binary-tree-inorder-traversal/

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
    public List<Integer> inorderTraversal(TreeNode root) {
        ArrayList<Integer> inorder = new ArrayList<Integer>();
        if(root != null) {
            inorder.addAll(inorderTraversal(root.left));
            inorder.add(root.val);
            inorder.addAll(inorderTraversal(root.right));
        }
        return inorder;
    }
}