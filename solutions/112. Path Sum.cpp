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
    
    bool isLeaf(TreeNode* root) {
        return root->left == nullptr && root->right == nullptr;
    }
    
    void helper(TreeNode* root, int currSum, int targetSum, bool& answer) {
        if(root == nullptr)
            return;
        
        currSum += root->val;
        
        if(isLeaf(root) && currSum == targetSum)
            answer = true;
        
        helper(root->left, currSum, targetSum, answer);
        helper(root->right, currSum, targetSum, answer);
        
        return;
    }
    
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool answer = false;
        helper(root, 0, targetSum, answer);
        return answer;
    }
};
