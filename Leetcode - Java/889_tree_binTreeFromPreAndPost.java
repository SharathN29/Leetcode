// https://leetcode.com/problems/construct-binary-tree-from-preorder-and-postorder-traversal/

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
    int preIndex = 0, postIndex = 0;
    public TreeNode constructFromPrePost(int[] pre, int[] post) {
        TreeNode root = new TreeNode(pre[preIndex++]);
        if(root.val != post[postIndex]) 
            root.left = constructFromPrePost(pre, post);
        if(root.val != post[postIndex])
            root.right = constructFromPrePost(pre, post);
        postIndex++;
        return root; 
    }
}