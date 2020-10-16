// https://leetcode.com/problems/binary-tree-vertical-order-traversal/

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
    public List<List<Integer>> verticalOrder(TreeNode root) {
        List<List<Integer>> res = new ArrayList();
        if (root == null) return res;
        
        Map<Integer, ArrayList<Integer>> map = new HashMap();
        Queue<TreeNode> q = new LinkedList();
        Queue<Integer> cols = new LinkedList();
        int min = 0, max = 0;
        
        q.add(root);
        cols.add(0);
        
        while (!q.isEmpty()) {
            TreeNode node = q.poll();
            int col = cols.poll();
            map.putIfAbsent(col, new ArrayList());
            map.get(col).add(node.val);
            
            if (node.left != null) {
                q.add(node.left);
                cols.add(col - 1);
                min = Math.min(min, col - 1);
            }
            
            if (node.right != null) {
                q.add(node.right);
                cols.add(col + 1);
                max = Math.max(max, col + 1);
            }
        }
        
        for (int i = min; i <= max; i++) {
            res.add(map.get(i));
        }
        
        return res;
    }
}