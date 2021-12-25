/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode smallerHead(0), greaterHead(0);
        ListNode* currPtr = head;
        ListNode *smallerTail = &smallerHead, *greaterTail = &greaterHead;
        
        while(currPtr != nullptr) {
            if(currPtr->val < x) {
                smallerTail->next = currPtr;
                smallerTail = smallerTail->next;
            } else {
                greaterTail->next = currPtr;
                greaterTail = greaterTail->next;
            }
            
            currPtr = currPtr->next;
        }
        
        smallerTail->next = greaterHead.next;
        greaterTail->next = nullptr;
        
        return smallerHead.next;
    }
};
