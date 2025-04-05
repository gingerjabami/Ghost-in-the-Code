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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {   
    ListNode* v1 = headA;
    ListNode* v2 = headB;
while (v1 != v2){
   v1 = v1->next;
   v2 = v2->next;
if(v1==v2)
    return v2;
if(v1==nullptr)
    v1=headB;
if(v2==nullptr)
        v2=headA;
    
    }
  return v1; 
        
    }
};