/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> answer;
        stack<TreeNode*> stk;
        TreeNode* currPtr = root;
        
        while(currPtr != nullptr or !stk.empty()) {
            while(currPtr != nullptr) {
                stk.push(currPtr);
                currPtr = currPtr->left;
            }
            
            currPtr = stk.top();
            stk.pop();
            
            answer.push_back(currPtr->val);
            currPtr = currPtr->right;
        }
        
        return answer;
    }
};
