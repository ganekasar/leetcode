class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        
        if(n < 3) 
            return {};
        
        vector<vector<int>> answer;
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++) {
            
            if(i > 0 && nums[i] == nums[i-1]) 
                continue;
            
            int target = 0 - nums[i];
            int low = i+1, high = n - 1;
            
            while(low < high) {
                int sum = nums[low] + nums[high];
                
                if(sum > target)
                    high--;
                else if(sum < target)
                    low++;
                else {
                    answer.push_back({nums[i], nums[low], nums[high]});
                    
                    low++;
                    high--;
                    
                    while(low < high && nums[high] == nums[high+1]) 
                        high--;
                    
                    while(low < high && nums[low-1] == nums[low]) 
                        low++;
                }    
            }
        }
        
        return answer;
    }
};
​
​
