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
    
    int height(TreeNode* root) {
        if(root == NULL)
            return 0;
        else {
            int lheight = height(root->left);
            int rheight = height(root->right);
            
            return max(lheight,rheight)+1;
        }
    }
    
    void addGivenLevel(TreeNode* root, int level, int i, vector<vector<int>>& res) {
        if(root == NULL)
            return;
        
        if(i == 0)
            res[level].push_back(root->val);
        else {
            addGivenLevel(root->left, level, i-1, res);
            addGivenLevel(root->right, level, i-1, res);
        }
    }
    
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        int h = height(root);
        vector<vector<int>> res(h);
        
        for(int level=0; level<h; level++)
            addGivenLevel(root, level, level, res);
        
        reverse(res.begin(), res.end());
