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
    map<int,int> inorderIndices;
    
    TreeNode* helper(vector<int>& postorder, int istart, int iend, int& index) {
        if(istart > iend)
            return nullptr;
        
        TreeNode* root = new TreeNode(postorder[index]);
        
        int pos = inorderIndices[postorder[index]];
        
        index--;
        
        root->right = helper(postorder, pos + 1, iend, index);
        root->left = helper(postorder, istart, pos - 1, index);
        
        return root;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int index = n - 1;
        
        for(int i = 0; i < n; i++)
            inorderIndices[inorder[i]] = i;
        
        return helper(postorder, 0, n - 1, index);
    }
};
