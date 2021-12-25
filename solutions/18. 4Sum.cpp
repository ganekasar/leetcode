class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<vector<int>> answer;
        
        for(int i = 0; i < n; i++) {
            for(int j = i+1; j < n; j++) {
                int remain = target - nums[i] - nums[j];
                
                int low = j+1, high = n-1;
                
                while(low < high) {
                    if(nums[low] + nums[high] == remain) {
                        vector<int> quadruplet = {nums[i], nums[j], nums[low], nums[high]};
                        answer.push_back(quadruplet);
                        
                        while(low < high && nums[low] == quadruplet[2])
                            low++;
                        
                        while(low < high && nums[high] == quadruplet[3])
                            high--;
                    } else if(nums[low] + nums[high] < remain)
                        low++;
                    else
                        high--;
                }
                
                while(j+1 < n && nums[j+1] == nums[j])
                    j++;
            }
            
            while(i+1 < n && nums[i+1] == nums[i])
                i++;
        }
        
        return answer;
    }
};
