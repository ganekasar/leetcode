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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode dummyHead(0);
        ListNode* ptr1 = l1;
        ListNode* ptr2 = l2;
        ListNode* currNode = &dummyHead;
        
        int carry = 0;
        
        while(ptr1 != nullptr or ptr2 != nullptr) {
            int x = (ptr1 != nullptr) ? ptr1->val : 0;
            int y = (ptr2 != nullptr) ? ptr2->val : 0;
            
            int currSum = carry + x + y;
            
            carry = currSum / 10;
            if(currSum >= 10)
                currSum -= 10;
            
            currNode->next = new ListNode(currSum);
            currNode = currNode->next;
            
            if(ptr1 != nullptr)
                ptr1 = ptr1->next;
            
            if(ptr2 != nullptr)
                ptr2 = ptr2->next;
        }
        
        if(carry != 0)
            currNode->next = new ListNode(carry);
        
        return dummyHead.next;
    }
};
