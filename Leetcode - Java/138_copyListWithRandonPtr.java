// https://leetcode.com/problems/copy-list-with-random-pointer/

/*
// Definition for a Node.
class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}
*/

class Solution {
    public Node copyRandomList(Node head) {
        Node next, iter = head;

        while(iter != null) {
        	next = iter.next; 
        	Node copy = new Node(iter.val);
        	iter.next = copy;
        	copy.next = next; 
        	iter = next; 
        }

        iter = head; 
        while(iter != null) {
        	if(iter.random != null) {
        		iter.next.random= iter.random.next; 
        	}
        	iter = iter.next.next; 
        }

        iter = head; 
        Node dummyhead = new Node(0);
        Node copy, copyiter = dummyhead;

        while(iter != null) {
        	next = iter.next.next; 
        	copy = iter.next;
        	copyiter.next = copy;
        	copyiter = copy;

        	iter.next = next;
        	iter = next;
        }

        return dummyhead.next;

    }
}