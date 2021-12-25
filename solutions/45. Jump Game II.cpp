class Solution {
public:
    int jump(vector<int>& nums) {
        int jumpsCount = 0, currEnd = 0, maxReach = 0;
        
        for(int i = 0; i < nums.size() - 1; i++) {
            maxReach = max(maxReach, i + nums[i]);
            
            if(i == currEnd) {
                jumpsCount++;
                currEnd = maxReach;
            }
        }
        
        return jumpsCount;
    }
};
