// Linked List Cycle 

// Given a linked list, determine if it has a cycle in it.

// To represent a cycle in the given linked list, we use an integer 
// pos which represents the position (0-indexed) in the linked list where 
// tail connects to. If pos is -1, then there is no cycle in the linked list.

#include <iostream>

using namespace std;

struct ListNode {
    int data = 0;
    ListNode * next = nullptr;
    ListNode(int d){
        data = d;
    }
};

void insert(ListNode * &head, int data) {
    ListNode * newNode = new ListNode(data);
    newNode -> next = head;
    head = newNode;
}

void printList(ListNode * head) {
    while(head){
        cout<<head->data << "-->";
        head = head -> next;
    }
    cout<< "nullptr" << endl;
}

bool hasCycle(ListNode *head) {
    if(head == NULL || head -> next == NULL)
        return false; 

    ListNode * slow = head;
    ListNode * fast = head -> next;
    
    while(slow != fast){
        if(fast == NULL || fast -> next == NULL)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true; 
}

int main() {
    ListNode * head = nullptr;
    insert(head, -4);
    insert(head, 0);
    insert(head, 2);
    insert(head, 3);
    cout << "Elements in the list : ";
    printList(head);
    if(hasCycle(head))
        cout<<"The linked list has cycle" << endl;
    else
        cout<<"No, the linked list doesnt have cycle" << endl;
}