// https://leetcode.com/problems/binary-tree-paths/

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
    public List<String> binaryTreePaths(TreeNode root) {
        List<String> answer = new ArrayList<String>();
        if(root != null) treePath(root, "", answer);
        return answer;
    }
    
    private void treePath(TreeNode root, String path, List<String> answer) {
        if(root.left == null && root.right == null) answer.add(path+root.val);
        if(root.left != null) treePath(root.left, path+root.val+"->", answer);
        if(root.right != null) treePath(root.right, path+root.val+"->", answer);
    }
}