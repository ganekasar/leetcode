/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    
    ListNode* getIntersection(ListNode* head) {
        ListNode* slowPtr = head;
        ListNode* fastPtr = head;
        
        while(fastPtr != nullptr && fastPtr->next != nullptr) {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
            
            if(slowPtr == fastPtr)
                return slowPtr;
        }
        
        return nullptr;
    }
    
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == nullptr)
            return nullptr;
        
        ListNode* intersect = getIntersection(head);
        
        if(intersect == nullptr)
            return nullptr;
        
        ListNode* ptr1 = head;
        ListNode* ptr2 = intersect;
        
        while(ptr1 != ptr2) {
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        
        return ptr1;
    }
