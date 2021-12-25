class Solution {
public:
    vector<vector<int>> allPermutations;
    
    void solve(vector<int>& nums, int mask, vector<int>& perm) {
        int count = __builtin_popcount(mask);
        int n = nums.size();
        
        if(count == n) {
            allPermutations.push_back(perm);
            return;
        }
        
        for(int i = 0; i < n; i++) {
            if(!(mask & (1 << i))) {
                perm.push_back(nums[i]);
                solve(nums, mask | (1 << i), perm);
                perm.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> perm;
        solve(nums, 0, perm);
        return allPermutations;
    }
};
