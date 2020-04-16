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
    int preIndex;
    Map<Integer, Integer> m = new HashMap<>();
    
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        preIndex = 0;
        int index = 0;
        for(int n : inorder) 
            m.put(n, index++);
        return helper(0, inorder.length-1, preorder, inorder);
    }
    
    public TreeNode helper(int left, int right, int[] preorder, int[] inorder) {
        if(left > right) return null;
        int rootVal = preorder[preIndex];
        TreeNode root = new TreeNode(rootVal);
        int index = m.get(rootVal);
        preIndex++;
        
        root.left = helper(left, index-1, preorder, inorder);
        root.right = helper(index+1, right, preorder, inorder);
        return root;
    }
}