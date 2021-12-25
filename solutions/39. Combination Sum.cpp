class Solution {
    void solve(vector<int> &candidates, int target, vector<vector<int>> &res, vector<int> &curr, int index) {
        if (target == false) {
            res.push_back(curr);
            return;
        }
            
        for (int i = index; i < candidates.size() && target >= candidates[i]; i++) {
            curr.push_back(candidates[i]);
            solve(candidates, target - candidates[i], res, curr, i);
            curr.pop_back();
        }
    }
    
public:
    vector<vector<int> > combinationSum(vector<int> &candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        vector<int> curr;
        solve(candidates, target, res, curr, 0);
        return res;
    }
};
