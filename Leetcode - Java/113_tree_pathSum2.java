// https://leetcode.com/problems/path-sum-ii/

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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> res = new ArrayList();
        List<Integer> path = new ArrayList();
        findPaths(root, sum, path, res);
        return res;
    }
    
    private void findPaths(TreeNode root, int sum, List<Integer> path, List<List<Integer>> res) {
        if (root == null) return;
        path.add(root.val);
        if (root.left == null && root.right == null && sum == root.val) {
            res.add(new ArrayList<>(path));
        }
        findPaths(root.left, sum - root.val, path, res);
        findPaths(root.right, sum - root.val, path, res);
        path.remove(path.size() - 1);
    }
}