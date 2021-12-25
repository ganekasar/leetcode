class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int answer = 1e6;
        int n = nums.size();
        
        sort(nums.begin(), nums.end());
        
        for(int i = 0; i < n; i++) {
            int low = i+1, high = n-1;
            
            while(low < high) {
                int currSum = nums[i] + nums[low] + nums[high];
                
                if(abs(target - currSum) < abs(answer - target))
                    answer = currSum;
                
                if(currSum == target)
                    return target;
                else if(currSum < target)
                    low++;
                else
                    high--;
            }
        }
        
        return answer;
    }
};
