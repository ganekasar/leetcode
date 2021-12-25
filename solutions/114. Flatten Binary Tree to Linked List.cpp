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
    void flatten(TreeNode* root) {
        if(root == NULL)
            return;
        
        flatten(root->left);
        flatten(root->right);
        
        TreeNode* prevRight = root->right;
        root->right = root->left;
        root->left = NULL;
        
        TreeNode* rightLast = root;
        
        while(rightLast->right)
            rightLast = rightLast->right;
        
        rightLast->right = prevRight;
        
        return;
    }
};
