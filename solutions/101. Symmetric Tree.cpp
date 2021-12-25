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
    
    bool isSymmetricRec(TreeNode* node1, TreeNode* node2) {
        if(node1 == nullptr and node2 == nullptr)
            return true;
        else if(node1 == nullptr or node2 == nullptr)
            return false;
        else if(node1->val != node2->val)
            return false;
        
        return isSymmetricRec(node1->left, node2->right) && isSymmetricRec(node1->right, node2->left);
    }
    
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetricRec(root->left, root->right);
    }
};
