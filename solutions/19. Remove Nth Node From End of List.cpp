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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* fastptr = head;
        
        for(int i = 0; i < n && fastptr != nullptr; i++)
            fastptr = fastptr->next;
        
        if(fastptr == nullptr) {
            ListNode* newHead = head->next;
            delete head;
            return newHead;
        }
        
        ListNode* slowptr = head;
        
        while(fastptr->next != nullptr) {
            slowptr = slowptr->next;
            fastptr = fastptr->next;
        }
        
        ListNode* nodeToRemove = slowptr->next;
        slowptr->next = slowptr->next->next;
        delete nodeToRemove;
        
        return head;
    }
};
