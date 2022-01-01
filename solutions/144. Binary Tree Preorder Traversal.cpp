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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> answer;
        
        if(root == nullptr)
            return answer;
        
        stack<TreeNode*> stk;
        
        stk.push(root);
        
        while(!stk.empty()) {
            TreeNode* currPtr = stk.top();
            stk.pop();
            
            answer.push_back(currPtr->val);
            
            if(currPtr->right != nullptr)
                stk.push(currPtr->right);
            
            if(currPtr->left != nullptr)
                stk.push(currPtr->left);
        }
        
        return answer;
    }
};
