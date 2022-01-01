/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
​
class Solution {
public:
    
    void buildLinks(Node* node, map<Node*, Node*>& Map) {
        
        Node* nodeCopy = new Node(node->val);
        Map[node] = nodeCopy;
        
        for(auto neigh : node->neighbors) {
            if(Map.find(neigh) == Map.end())
                buildLinks(neigh, Map);
            nodeCopy->neighbors.push_back(Map[neigh]);
        }
            
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL)
            return node;
        
        map<Node*,Node*> Map;
