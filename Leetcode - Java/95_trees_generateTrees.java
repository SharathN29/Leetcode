// https://leetcode.com/problems/unique-binary-search-trees-ii/

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
    public List<TreeNode> generateTrees(int n) {
        if (n == 0) {
            return new LinkedList<TreeNode>();
        }
        return generateBST(1, n);
    }
    
    private LinkedList<TreeNode> generateBST(int start, int end) {
        LinkedList<TreeNode> allBST = new LinkedList<TreeNode>();
        if (start > end) {
            allBST.add(null);
            return allBST;
        }
        
        for (int i = start; i <= end; i++) {
            LinkedList<TreeNode> leftTrees = generateBST(start, i - 1);
            LinkedList<TreeNode> rightTrees = generateBST(i + 1, end);
            
            for (TreeNode l : leftTrees) {
                for (TreeNode r : rightTrees) {
                    TreeNode currentTree = new TreeNode(i);
                    currentTree.left = l;
                    currentTree.right = r;
                    allBST.add(currentTree);
                }
            }
        }
        
        return allBST;
    }
}