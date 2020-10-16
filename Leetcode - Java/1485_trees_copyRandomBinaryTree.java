// https://leetcode.com/problems/clone-binary-tree-with-random-pointer/

/**
 * Definition for Node.
 * public class Node {
 *     int val;
 *     Node left;
 *     Node right;
 *     Node random;
 *     Node() {}
 *     Node(int val) { this.val = val; }
 *     Node(int val, Node left, Node right, Node random) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *         this.random = random;
 *     }
 * }
 */

class Solution {
    public NodeCopy copyRandomBinaryTree(Node root) {
        Map<Node, NodeCopy> map = new HashMap();
        return dfs(root, map);
    }
    
    public NodeCopy dfs(Node node, Map<Node, NodeCopy> map) {
        if (node == null) return null; 
        if (map.containsKey(node)) return map.get(node);
        NodeCopy newNode = new NodeCopy(node.val);
        map.put(node, newNode);
        
        newNode.left = dfs(node.left, map);
        newNode.right = dfs(node.right, map);
        newNode.random = dfs(node.random, map);
        
        return newNode;
    }
}