// Palindrome Linked List

// Given a singly linked list, determine if it is a palindrome.

// Example 1:

// Input: 1->2
// Output: false
// Example 2:

// Input: 1->2->2->1
// Output: true

#include <iostream> 

using namespace std; 

struct ListNode{
    int data = 0;
    ListNode * next = nullptr;
    ListNode(int d) {
        data = d;
    }
};

void insert(ListNode * &head, int data){
    ListNode * new_node = new ListNode(data);
    new_node -> next = head;
    head = new_node;
}

void printList(ListNode * head) {
    while(head) {
        cout<<head->data<<"-->";
        head = head->next;
    }
    cout<<"nullptr" << endl;
}

bool isPalindrome(ListNode* head){
    int count = 0;
    ListNode * node = head;

    // counts the number of elements in the given list
    while(node) {
        node = node -> next;
        count++;
    }

    node = head;
    ListNode * pre = NULL;
    int half = count / 2;

    while(half > 0) {
        ListNode * temp = node -> next;
        node -> next = pre;
        pre = node; 
        node = temp;
        half--;
    }

    ListNode * h1 = NULL;
    ListNode * h2 = NULL;

    h1 = pre;
    h2 = count % 2 == 0 ? node : node -> next;

    while(h1) {
        if(h1->data != h2->data) return false;
        h1 = h1->next;
        h2 = h2->next;
    }
    return true;
}

int main(){
    ListNode * head = nullptr;
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 2);
    insert(head, 1);
    cout<<"Given singly linked List : ";
    printList(head);
    if(isPalindrome(head)){
        cout<<"The given linked list is a palindrome " << endl;
    } else {
        cout<<"The given linked list is not a palindrome " << endl;
    }
}