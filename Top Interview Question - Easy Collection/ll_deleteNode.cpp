// Delete a node in linked list
// https://leetcode.com/explore/interview/card/top-interview-questions-easy/93/linked-list/553/

#include<iostream> 

using namespace std;

struct ListNode {
    int data = 0;
    ListNode * next = nullptr;
};

void insert(ListNode * &head, int data){
    ListNode * newNode = new ListNode;
    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

void printList(ListNode * head){
    while (head){
        std::cout<<head->data<<"-->";
        head = head->next;
    }
    std::cout<<"nullptr"<<std::endl;
}

ListNode* removeNthFromEnd(ListNode* head, int n){

}

int main() {
    ListNode * node = nullptr;

}