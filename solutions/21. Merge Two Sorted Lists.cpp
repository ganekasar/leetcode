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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode preHead(0);
        ListNode* currNode = &preHead;
        
        while(l1 != nullptr && l2 != nullptr) {
            if(l1->val <= l2->val) {
                currNode->next = l1;
                l1 = l1->next;
            } else {
                currNode->next = l2;
                l2 = l2->next;
            }
            
            currNode = currNode->next;
        }
        
        if(l1 != nullptr)
            currNode->next = l1;
        else if(l2 != nullptr)
            currNode->next = l2;
        
        return preHead.next;
    }
};
