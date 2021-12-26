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
    
    void helper(TreeNode* root, int curr, int& answer) {
        if(root == nullptr)
            return;
        
        curr = curr*10 + root->val;
        
        if(root->left == nullptr && root->right == nullptr)
            answer += curr;
        else {
            helper(root->left, curr, answer);
            helper(root->right, curr, answer);
        }
    }
    
public:
    int sumNumbers(TreeNode* root) {
        int answer = 0;
        int curr = 0;
        helper(root, curr, answer);
        return answer;
    }
};
