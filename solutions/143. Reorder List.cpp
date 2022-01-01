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
    
    ListNode* getMid(ListNode* head) {
        ListNode* fastPtr = head, *slowPtr = head;
        
        while(fastPtr != nullptr && fastPtr->next != nullptr) {
            fastPtr = fastPtr->next->next;
            slowPtr = slowPtr->next;
        }
        
        return slowPtr;
    }
    
    ListNode* reverseList(ListNode* head) {
        ListNode* prevNode = nullptr, *currNode = head;
        
        while(currNode != nullptr) {
            ListNode* nextNode = currNode->next;
            currNode->next = prevNode;
            
            prevNode = currNode;
            currNode = nextNode;
        }
        
        return prevNode;
    }
    
public:
    void reorderList(ListNode* head) {
        ListNode* midNode = getMid(head);
        
        midNode->next = reverseList(midNode->next);
        
        ListNode dummyHead(0);
        
