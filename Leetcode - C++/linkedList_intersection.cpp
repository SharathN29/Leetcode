#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *list1 = headA, *list2 = headB;
    if(list1 == NULL || list2 == NULL) return NULL;
    while(list1 != NULL && list2 != NULL && list1 != list2){
    	list1 = list1->next;
    	list2 = list2->next;
    	if(list1 == list2) return list1;
    	if(list1 == NULL) list1 = headB;
    	if(list2 == NULL) list2 = headA;
    }
    return list1;
}