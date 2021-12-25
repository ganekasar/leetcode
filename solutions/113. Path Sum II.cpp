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
    
    void pathSumRec(TreeNode* root, int remainSum, vector<int>& curr, vector<vector<int>>& answer) {
        if(root == nullptr)
            return;
        
        bool isLeaf = (root->left == nullptr) and (root->right == nullptr);
        
        remainSum -= root->val;
        curr.push_back(root->val);
        
        if(isLeaf) {
            if(remainSum == 0) 
                answer.push_back(curr);
            curr.pop_back();
            return;
        }
        
        pathSumRec(root->left, remainSum, curr, answer);
        pathSumRec(root->right, remainSum, curr, answer);
        
        curr.pop_back();
    }
    
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> answer;
        vector<int> curr;
        pathSumRec(root, targetSum, curr, answer);
        return answer;
    }
};
