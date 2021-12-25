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
    
    ListNode* reverseList(ListNode* head, int k) {
        ListNode* prevPtr = nullptr;
        ListNode* currPtr = head;
        
        while(k > 0) {
            ListNode* nextPtr = currPtr->next;
            currPtr->next = prevPtr;
            prevPtr = currPtr;
            currPtr = nextPtr;
            k--;
        }
        
        return prevPtr;
    }
    
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* currPtr = head;
        int count = 0;
        
        while(count < k && currPtr != nullptr) {
            currPtr = currPtr->next;
            count++;
        }
        
        if(count == k) {
            ListNode* reversedHead = reverseList(head, k);
            head->next = reverseKGroup(currPtr, k);
            return reversedHead;
        }
        
        return head;
    }
