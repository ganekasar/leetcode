/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == nullptr or head->next == nullptr)
            return false;
        
        ListNode* slowPtr = head;
        ListNode* fastPtr = head->next;
        
        while(fastPtr != nullptr && fastPtr->next != nullptr) {
            if(slowPtr == fastPtr)
                return true;
            
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        
        return false;
    }
};
