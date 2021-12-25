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
    ListNode* deleteDuplicates(ListNode* head) {
        
        //Base Condition
        //If list if empty or contains only one element
        if(head == NULL or head->next == NULL)
            return head;
        
        //If there are duplicates at start, remove them
        if(head->val == (head->next)->val) {
            int val = head->val;
            
            while(head and head->val == val)
                head = head->next;
            
            return deleteDuplicates(head);
        }
        
        head->next = deleteDuplicates(head->next);
        
        return head;
    }
};
