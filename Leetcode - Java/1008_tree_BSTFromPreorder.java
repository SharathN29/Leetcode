// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

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

	int pre_index; 
	Map<Integer, Integer> map;

    public TreeNode bstFromPreorder(int[] preorder) {
        int[] inorder = new int[preorder.length];
        map = new HashMap<Integer, Integer>();
        
        for(int i = 0; i < preorder.length; i++) {
        	inorder[i] = preorder[i];
        }
        Arrays.sort(inorder);
        pre_index = 0;
        int index = 0;

        for(int n : inorder) {
        	map.put(n, index++);
        }

        return helper(0, inorder.length-1, preorder, inorder);
    }

    private TreeNode helper(int left, int right, int[] preorder, int[] inorder) {
    	if(left > right) return null;

    	int root_val = preorder[pre_index];
    	TreeNode root = new TreeNode(root_val);
    	int index = map.get(root_val);
    	pre_index++;

    	root.left = helper(left, index-1, preorder, inorder);
    	root.right = helper(index+1, right, preorder, inorder);

    	return root;
    }
}