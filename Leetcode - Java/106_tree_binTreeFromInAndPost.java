// https://leetcode.com/problems/construct-binary-tree-from-inorder-and-postorder-traversal/

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
    int postIndex = 0;
    Map<Integer, Integer> m = new HashMap<>();
    
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        postIndex = inorder.length-1;
        int index = 0;
        for(int n : inorder) 
            m.put(n, index++);
        return helper(0, inorder.length-1, inorder, postorder);
    }
    
    public TreeNode helper(int left, int right, int[] inorder, int[] postorder) {
        if(left > right) return null;
        
        int rootVal = postorder[postIndex];
        TreeNode root = new TreeNode(rootVal);
        int index = m.get(rootVal);
        postIndex--;
        
        root.right = helper(index+1, right, inorder, postorder);
        root.left = helper(left, index-1, inorder, postorder);
        return root;
    }
}