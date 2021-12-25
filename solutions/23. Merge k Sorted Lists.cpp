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
    
    class compare {
        public:
            bool operator()(const ListNode *a, const ListNode *b) {
                return a->val > b->val;
            }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode dummyHead(0);
        ListNode* listTail = &dummyHead;
        
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;
        
        for(int i = 0; i < lists.size(); i++) {
            if(lists[i] != nullptr) 
                pq.push(lists[i]);
        }
        
        while(!pq.empty()) {
            ListNode* currNode = pq.top();
            pq.pop();
            
            listTail->next = currNode;
            listTail = listTail->next;
            
            currNode = currNode->next;
            
            if(currNode != nullptr)
                pq.push(currNode);
        }
        
        return dummyHead.next;
    }
};
