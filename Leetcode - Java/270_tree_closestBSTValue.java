// https://leetcode.com/problems/closest-binary-search-tree-value/

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
    public int closestValue(TreeNode root, double target) {
        List<Integer> nums = new ArrayList();
        inorder(root, nums);
        return Collections.min(nums, new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return Math.abs(o1 - target) < Math.abs(o2 - target) ? -1 : 1;
            }
        }); 
    }
    
    private void inorder(TreeNode node, List<Integer> nums) {
        if(node == null) return;
        inorder(node.left, nums);
        nums.add(node.val);
        inorder(node.right, nums);
    }
}