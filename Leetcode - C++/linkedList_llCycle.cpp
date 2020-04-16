#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *detectCycle(ListNode *head) {
    if(head == NULL || head->next == NULL) return NULL; 

    ListNode *firstPtr = head;
    ListNode *secondPtr = head;
    bool hasCycle = false;

    while(firstPtr != NULL && secondPtr != NULL) {
        firstPtr = firstPtr->next;
        if(secondPtr == NULL) return NULL;
        secondPtr = secondPtr->next->next;
        if(firstPtr == secondPtr) {
            hasCycle == true;
            break;
        }
    }

    if(!hasCycle) return NULL;
    firstPtr = head;
    while(firstPtr != secondPtr) {
        firstPtr = firstPtr->next;
        secondPtr = secondPtr->next;
    }
    return firstPtr;
}

// int main() {
//     struct ListNode *root = new ListNode();;
//     ListNode * second = NULL;
//     ListNode *third = NULL;
//     ListNode *fourth = NULL
//     ListNode *fifth = NULL;

//     root =  new ListNode(); 

// }