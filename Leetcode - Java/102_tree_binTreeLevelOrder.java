// https://leetcode.com/problems/binary-tree-level-order-traversal/

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
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer>> levels = new ArrayList<List<Integer>>();
        if(root == null) return levels;
        
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        int level = 0;
        while(!q.isEmpty()) {
            levels.add(new ArrayList<Integer>());
            int len = q.size();
            for(int i = 0; i < len; i++) {
                TreeNode node = q.remove();
                levels.get(level).add(node.val);
                if(node.left != null) q.add(node.left);
                if(node.right != null) q.add(node.right);
            }
            level++;
        }
        return levels;
    }
}