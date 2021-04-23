// https://leetcode.com/problems/path-sum-iii/

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
    int count = 0;
    int k;
    Map<Integer, Integer> map = new HashMap();
    
    public int pathSum(TreeNode root, int sum) {
        k = sum;
        preorder(root, 0);
        return count;
    }
    
    public void preorder(TreeNode root, int currSum) {
        if (root == null) return;
        currSum += root.val;
        if (currSum == k) count++;
        count += map.getOrDefault(currSum - k, 0);
        map.put(currSum, map.getOrDefault(currSum, 0) + 1);
        preorder(root.left, currSum);
        preorder(root.right, currSum);
        map.put(currSum, map.get(currSum) -1);
    }
}