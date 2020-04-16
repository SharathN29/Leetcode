// https://leetcode.com/problems/leaf-similar-trees/

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
    public boolean leafSimilar(TreeNode root1, TreeNode root2) {
        List<Integer> list1 = new ArrayList<>();
        List<Integer> list2 = new ArrayList<>();
        findLeaf(root1, list1);
        findLeaf(root2, list2);
        return list1.equals(list2);
    }
    
    private void findLeaf(TreeNode node, List<Integer> list) {
        if(node != null) {
            if(node.left == null && node.right == null) {
                list.add(node.val);
            }
            findLeaf(node.left, list);
            findLeaf(node.right, list);
        }
    }
}