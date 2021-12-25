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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode dummy(0);
        dummy.next = head;
        ListNode* prevptr = &dummy;
        right -= left;
        
        for(int i = 1; i < left; i++)
            prevptr = prevptr->next;
        
        ListNode* currptr = prevptr->next;
        ListNode* nextptr;
        
        while(right--) {
            nextptr = currptr->next;
            currptr->next = nextptr->next;
            
            nextptr->next = prevptr->next;
            prevptr->next = nextptr;
        }
        
        return dummy.next;
    }
};
