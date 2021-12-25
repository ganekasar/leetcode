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
    
    int isHeightBalancedRecursive(TreeNode* root, bool& ifBalanced) {
        // BASE CONDITION
        if(root == nullptr)
            return 0;
​
        int leftHeight = isHeightBalancedRecursive(root->left, ifBalanced);
        int rightHeight = isHeightBalancedRecursive(root->right, ifBalanced);
​
        if(abs(leftHeight - rightHeight) > 1)
            ifBalanced = false;
​
        return 1 + max(leftHeight, rightHeight);
    }
    
public:
    bool isBalanced(TreeNode* root) {
        bool answer = true;
        isHeightBalancedRecursive(root, answer);
        return answer;
    }
};
