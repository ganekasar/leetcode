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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answer;
        
        if(root == nullptr)
            return answer;
        
        queue<TreeNode*> q;
        
        q.push(root);
        bool isReverse = false;
        
        while(!q.empty()) {
            int levelSize = (int)q.size();
            vector<int> currLevel;
            
            while(levelSize--) {
                TreeNode* currNode = q.front();
                q.pop();
                
                currLevel.push_back(currNode->val);
                
                if(currNode->left != nullptr)
                    q.push(currNode->left);
                
                if(currNode->right != nullptr)
                    q.push(currNode->right);
            }
            
            if(isReverse)
                reverse(currLevel.begin(), currLevel.end());
            
            answer.push_back(currLevel);
