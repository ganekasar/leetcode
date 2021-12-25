class Solution {
    
    void solve(vector<int>& nums, int index, vector<int>& curr, vector<vector<int>>& answer) {
        if(index == nums.size()) {
            answer.push_back(curr);
            return;
        }
        
        // not included
        solve(nums, index+1, curr, answer);
        
        // included
        curr.push_back(nums[index]);
        solve(nums, index+1, curr, answer);
        curr.pop_back();
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> answer;
        vector<int> curr;
        
        solve(nums, 0, curr, answer);
        
        return answer;
    }
};
