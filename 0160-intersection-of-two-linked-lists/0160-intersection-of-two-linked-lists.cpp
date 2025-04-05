/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {   ListNode* v1 = headA;
    ListNode* v2 = headB;
    while (v1 != v2){
   
            v1 = v1 ? v1->next : headA;
            v2 = v2 ? v2->next: headB;
        
    }
    return v1;
        
    }
};