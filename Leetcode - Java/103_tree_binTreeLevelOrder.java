// https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/

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
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        List<List<Integer>> level = new ArrayList<List<Integer>>();
        if(root == null) return level;
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.add(root);
        boolean order = true; 
        
        while(!q.isEmpty()) {
            List<Integer> temp = new ArrayList<>();
            int len = q.size();
            for(int i = 0; i < len; i++) {
                TreeNode n = q.poll();
                if(order) temp.add(n.val);
                else temp.add(0, n.val);
                if(n.left != null) q.add(n.left);
                if(n.right != null) q.add(n.right);
            }
            level.add(temp);
            order = !order;
        }
        return level;
    }
}