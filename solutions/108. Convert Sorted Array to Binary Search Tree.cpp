class Solution {
    
    TreeNode* sortedArrayToBSTRec(vector<int>& nums, int low, int high) {
        if(low > high)
            return nullptr;
        
        if(low == high)
            return (new TreeNode(nums[low]));
        
        int mid = low + (high - low)/2;
        
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTRec(nums, low, mid-1);
        root->right = sortedArrayToBSTRec(nums, mid+1, high);
        
        return root;
    }
    
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size();
        return sortedArrayToBSTRec(nums, 0, n-1);
    }
};
