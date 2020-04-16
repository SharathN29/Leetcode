// https://leetcode.com/problems/binary-tree-postorder-traversal/

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
    public List<Integer> postorderTraversal(TreeNode root) {
        ArrayList<Integer> postorder = new ArrayList<Integer>();
        if(root != null) {
            postorder.addAll(postorderTraversal(root.left));
            postorder.addAll(postorderTraversal(root.right));
            postorder.add(root.val);
        }
        return postorder; 
    }
}