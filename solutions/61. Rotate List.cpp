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
    ListNode* rotateRight(ListNode* head, int k) {
        
        if(head == nullptr or head->next == nullptr)
            return head;
        
        int nodesCount = 0;
        
        ListNode* currPtr = head, *lastNode = nullptr;
        
        while(currPtr != nullptr) {
            lastNode = currPtr;
            currPtr = currPtr->next;
            nodesCount++;
        }
        
        k %= nodesCount;
        
        if(k == 0)
            return head;
        
        currPtr = head;
        
        for(int i = 0; i < nodesCount - k - 1; i++) 
            currPtr = currPtr->next;
        
        ListNode* newHead = currPtr->next;
        currPtr->next = nullptr;
        lastNode->next = head;
        
        return newHead;
    }
};
