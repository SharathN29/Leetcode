// Merge Two sorted lists

// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together 
// the nodes of the first two lists.

// Example:

// Input: 1->2->4, 1->3->4
// Output: 1->1->2->3->4->4

#include <iostream>

using namespace std;

struct ListNode {
    int data = 0;
    ListNode * next = nullptr;
    ListNode(int d) {
        data = d;
    }
};

void insert(ListNode * &head, int data) {
    ListNode * new_node = new ListNode(data);
    new_node ->next = head;
    head = new_node;
}

void printList(ListNode * head) {
    while(head){
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<"nullptr" << endl;
}

ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode * result = NULL;
    if(l1 == NULL) return l2;
    if(l2 == NULL) return l1;
    if(l1->data <= l2->data){
        result = l1;
        result->next = mergeTwoLists(l1->next, l2);
    } else {
        result = l2;
        result->next = mergeTwoLists(l1, l2->next);
    }
    return result;
}

int main() {
    ListNode * l1 = nullptr;
    ListNode * l2 = nullptr;
    insert(l1, 6);
    insert(l1, 2);
    insert(l1, 1);
    cout<<"First list : ";
    printList(l1);
    insert(l2, 4);
    insert(l2, 8);
    insert(l2, 1);
    cout<<"Second list : ";
    printList(l2);
    ListNode * result = mergeTwoLists(l1, l2);
    cout<<"Two lists after merging : ";
    printList(result);
}