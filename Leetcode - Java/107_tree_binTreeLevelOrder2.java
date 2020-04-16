// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    public List<List<Integer>> levelOrderBottom(TreeNode root) {
        List<List<Integer>> level = new ArrayList<List<Integer>>();
        if(root == null) return level;
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.offer(root);
        
        while(!q.isEmpty()) {
            List<Integer> temp = new ArrayList<Integer>();
            int size = q.size();
            for(int i = 0; i < size; i++) {
                if(q.peek().left != null) q.add(q.peek().left);
                if(q.peek().right != null) q.add(q.peek().right);
                temp.add(q.poll().val);
            }
            level.add(0,temp);
        }
        return level;
    }
}