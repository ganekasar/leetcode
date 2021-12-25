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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr or head->next == nullptr)
            return head;
        
        ListNode dummy(0);
        ListNode* prevNode = &dummy;
        ListNode* currNode = head;
        
        while(currNode != nullptr && currNode->next != nullptr) {
            ListNode* nextNode = currNode->next;
            currNode->next = nextNode->next;
            nextNode->next = currNode;
            
            prevNode->next = nextNode;
            prevNode = currNode;
            
            currNode = prevNode->next;
        }
        
        return dummy.next;
    }
};
