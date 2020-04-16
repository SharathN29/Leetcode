// https://leetcode.com/problems/binary-tree-preorder-traversal/

// Definition for a binary tree node.

import java.util.*;

// public class TreeNode {
//     int val;
//     TreeNode left;
//     TreeNode right;
//     TreeNode(int x) { val = x; }
// }
 
class Solution {
    public List<Integer> preorderTraversal(TreeNode root) {
        ArrayList<Integer> preorder = new ArrayList<Integer>();
        if(root != null) {
            preorder.add(root.val);
            preorder.addAll(preorderTraversal(root.left));
            preorder.addAll(preorderTraversal(root.right));
        }
        return preorder; 
    }
}