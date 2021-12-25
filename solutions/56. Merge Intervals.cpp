class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> merged;
        
        sort(intervals.begin(), intervals.end());
        
        for(vector<int> interval : intervals) {
            if(merged.empty() or merged.back()[1] < interval[0])
                merged.push_back(interval);
            else
                merged.back()[1] = max(merged.back()[1], interval[1]);
        }   
        
        return merged;
    }
};
