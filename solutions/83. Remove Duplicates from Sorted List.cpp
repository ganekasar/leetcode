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
        if(head == nullptr or head->next == nullptr)
            return head;
        
        ListNode* currNode = head;
        
        while(currNode != nullptr && currNode->next != nullptr) {
            ListNode* nextNode = currNode->next;
            
            if(currNode->val == nextNode->val) {
                currNode->next = nextNode->next;
                delete nextNode;
            } else 
                currNode = currNode->next;
        }
        
        return head;
    }
};
