#include <iostream>
#include <unordered_map>

using namespace std; 

struct ListNode {
    int data = 0;
    ListNode * next = nullptr;
    ListNode ( int d ) {
        data = d;
        next = nullptr;
    } 
};

void insert(ListNode * &head, int data){
    ListNode * newNode = new ListNode(data);
    newNode->next = head;
    head = newNode;
}

void printList(ListNode * head) {
    while(head){
        std::cout<<head->data<<"-->";
        head = head->next;
    }
    std::cout << "null" << std::endl;
}

ListNode* removeZeroSumSublists(ListNode* head) {
    ListNode dummy(0), *cur = &dummy; 
    dummy.next = head; 
    int prefix = 0;
    unordered_map<int, ListNode*> zero;
    while(cur) {
        prefix += cur->data;
        if(zero.count(prefix)){
            cur = zero[prefix] -> next;
            int p = prefix + cur->data;
            while (p != prefix) {
                zero.erase(p);
                cur = cur->next;
                p += cur->data;
            }
        } else {
            zero[prefix] = cur;
        }
        cur = cur->next;
    }
    printList(&dummy);
    return dummy.next;
}

int main() {
    ListNode * list1 = nullptr;
    insert(list1, 1);
    insert(list1, 2);
    insert(list1, -3);
    insert(list1, 1);
    insert(list1, 3);
    removeZeroSumSublists(list1);
}