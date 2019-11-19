// Reverse Linked List

// Reverse a singly linked list.

// Example:

// Input: 1->2->3->4->5->NULL
// Output: 5->4->3->2->1->NULL

#include <iostream>

using namespace std;

struct ListNode {
    int data = 0;
    ListNode * next = nullptr;
    ListNode (int d) {
        data= d;
    }
};

void insert(ListNode * &head, int data) {
    ListNode * new_node = new ListNode(data);
    new_node->next = head;
    head = new_node;
}

void printList(ListNode * head) {
    while (head) {
        cout<<head->data << "-->";
        head = head->next;
    }
    cout<<"nullptr" << endl;
}

ListNode* reverseList(ListNode* head) {
    ListNode *temp  = nullptr, *nextNode = nullptr;
    while(head) {
        nextNode = head->next;
        head->next = temp;
        temp = head;
        head = nextNode;
    }
    return temp;
}

int main() {
    ListNode * head = nullptr;
    insert(head, 5);
    insert(head, 4);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);
    cout<<"List items before reversing : ";
    printList(head);
    head = reverseList(head);
    cout<<"List Items after reversing : ";
    printList(head);
}