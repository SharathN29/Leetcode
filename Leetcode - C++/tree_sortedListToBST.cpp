#include <iostream>

using namespace std; 

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

TreeNode *sortedListToBST(ListNode *head) {
    return sortedListToBST(head, NULL);
}

TreeNode *sortedListToBST(ListNode *head, ListNode *tail) {
    if(head == tail) return NULL;
    ListNode *mid = head, *temp = head; 
    while(temp != NULL && temp->next != NULL) {
        mid = mid->next;
        temp = temp->next->next;
    }
    TreeNode *root = new TreeNode(mid->val);
    root->left = sortedListToBST(head, mid);
    root->right = sortedListToBST(mid->next, tail);
    return root;
}
 