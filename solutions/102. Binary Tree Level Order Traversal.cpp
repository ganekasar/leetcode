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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levels;
        
        if(root == nullptr)
            return levels;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()) {
            int currSize = q.size();
            vector<int> currLevel;
            
            while(currSize--) {
                TreeNode* currNode = q.front();
                q.pop();
                
                currLevel.push_back(currNode->val);
                
                if(currNode->left != nullptr)
                    q.push(currNode->left);
                
                if(currNode->right != nullptr)
                    q.push(currNode->right);
            }
            
            levels.push_back(currLevel);
        }
        
        return levels;
    }
};
