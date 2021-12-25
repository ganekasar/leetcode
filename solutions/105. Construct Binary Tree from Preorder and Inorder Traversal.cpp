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
    TreeNode *helper(vector<int>& preorder, vector<int>& inorder, int pstart, int pend, int istart, int iend) {
        if(istart > iend) 
            return nullptr;
        
        TreeNode *root = new TreeNode(preorder[pstart]);
        int pos;
        
        for(int i = istart; i < iend; i++) {
            if(inorder[i] == root->val) {
                pos = i;
                break;
            }
        }
        
        root->left = helper(preorder, inorder, pstart + 1, pstart + pos - istart, istart, pos - 1);
        root->right = helper(preorder, inorder, pstart + pos - istart + 1, pend, pos + 1, iend);
        
        return root;
    }
    
public:
    TreeNode *buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        return helper(preorder, inorder, 0, n - 1, 0, n - 1);
    }
};
