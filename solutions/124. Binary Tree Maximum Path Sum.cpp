class Solution {
    
    int helper(TreeNode* root, int& answer) {
        if(root == nullptr)
            return 0;
        
        int leftResult = helper(root->left, answer);
        int rightResult = helper(root->right, answer);
        
        int currAnswer = root->val + leftResult + rightResult;
        
        answer = max(answer, currAnswer);
        
        int maxSegmentSum = max(0, root->val + max(leftResult, rightResult));
        
        return maxSegmentSum;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        int answer = INT_MIN;
        helper(root, answer);
        return answer;
    }
};
