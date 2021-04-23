// https://leetcode.com/problems/sum-of-left-leaves/

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
// class Solution {
//     public int sumOfLeftLeaves(TreeNode root) {
//         if (root == null) return 0;
//         int ans = 0; 
        
//         if (root.left != null) {
//             if (root.left.left == null && root.left.right == null) {
//                 ans += root.left.val;
//             } else {
//                 ans += sumOfLeftLeaves(root.left);
//             }
//         }
//         ans += sumOfLeftLeaves(root.right);
//         return ans;
//     } 
// }

class Solution {
    public int sumOfLeftLeaves(TreeNode root) {
        if (root == null) return 0;
        int ans = 0;
        
        Queue<TreeNode> queue = new LinkedList();
        queue.offer(root);
        
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node.left != null) {
                if (node.left.left == null && node.left.right == null) {
                    ans += node.left.val;
                } else {
                    queue.offer(node.left);
                }
            } 
            
            if (node.right != null) {
                queue.offer(node.right);
            }
        }
        return ans;
    }
}