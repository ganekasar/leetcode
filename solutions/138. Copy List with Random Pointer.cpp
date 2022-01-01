class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node *currPtr = head; 
        
        // First round: make copy of each node,
        // and link them together side-by-side in a single list.
        while(currPtr != nullptr) {
            Node *nextPtr = currPtr->next;
​
            Node *newNode = new Node(currPtr->val);
            currPtr->next = newNode;
            newNode->next = nextPtr;
​
            currPtr = nextPtr;
        }
​
        // Second round: assign random pointers for the copy nodes.
        currPtr = head;
        
        while(currPtr != nullptr) {
            if (currPtr->random != nullptr) 
                currPtr->next->random = currPtr->random->next;
            
            currPtr = currPtr->next->next;
        }
​
        // Third round: restore the original list, and extract the copy list.
        currPtr = head;
        Node dummyHead(0);
        Node *copy = &dummyHead;
​
        while (currPtr != NULL) {
            Node* nextPtr = currPtr->next->next;
​
            copy->next = currPtr->next;
​
            // restore the original list
            currPtr->next = nextPtr;
​
            copy = copy->next; 
            currPtr = nextPtr;
        }
​
        return dummyHead.next;
