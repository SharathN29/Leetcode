//Remove Nth node from the end of the list 

// Given a linked list, remove the n-th node from the end of list and return its head.

// Example:

// Given linked list: 1->2->3->4->5, and n = 2.

// After removing the second node from the end, the linked list becomes 1->2->3->5.
// Note:

// Given n will always be valid.

#include <iostream> 

using namespace std; 

struct ListNode
{
    int data = 0;
    ListNode * next = nullptr;
    ListNode(int d) {
        data = d;
    }
};

void insert(ListNode * &head, int data) {
    ListNode * newNode = new ListNode(data);
    newNode -> next = head;
    head = newNode; 
}

void printList (ListNode * head) {
    while (head) {
        cout<<head -> data << "-->";
        head = head->next;
    }
    cout<<"nullptr" << endl;
}

ListNode* removeNthFromEnd(ListNode* head, int n) {
    if(!head)
        return nullptr;

    ListNode *new_head = new ListNode(-1);
    new_head -> next = head;

    ListNode *temp1 = new_head, *temp2 = new_head;

    for(int i = 0; i < n; i++)
        temp1 = temp1->next;

    while(temp1->next){
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    ListNode * delete_node = temp2->next;
    temp2->next = temp2->next->next;

    delete delete_node;
    
    return new_head->next;
}

int main() {
    ListNode * head = nullptr;
    insert(head,6);
    insert(head,5);
    insert(head,4);
    insert(head,3);
    insert(head,2);
    insert(head,1);
    cout<<"Nodes of the linked list before removing the node : ";
    printList(head);
    removeNthFromEnd(head, 3);
    cout<<endl<< "Nodes of the linked list after removeing 3rd node from the end : ";
    printList(head); 
}


