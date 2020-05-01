// https://leetcode.com/problems/maximum-binary-tree/

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
    public TreeNode constructMaximumBinaryTree(int[] nums) {
        return construct(nums, 0, nums.length);
    }
    
    private TreeNode construct(int[] nums, int left, int right) {
        if(left == right) return null;
        int max_index = max(nums, left, right);
        TreeNode root = new TreeNode(nums[max_index]);
        root.left = construct(nums, left, max_index);
        root.right = construct(nums, max_index+1, right);
        
        return root; 
    }
    
    private int max(int[] nums, int left, int right) {
        int max_index = left; 
        for(int i = left; i < right; i++) {
            if(nums[max_index] < nums[i])
                max_index = i;
        }
        return max_index;
    }
}

// Time : O(n^2), Space : O(n)