class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        bool checkOne = false;
        int n = nums.size();
        
        for(int x : nums) {
            if(x == 1) {
                checkOne = true;
                break;
            }
        }
        
        if(!checkOne)
            return 1;
        
        for(int &x : nums) {
            if(x <= 0 or x > n)
                x = 1;
        }
        
        for(int i = 0; i < n; i++) {
            int pos = abs(nums[i]);
            
            if(pos == n)
                pos = 0;
            
            nums[pos] = - abs(nums[pos]);
        }
        
        for(int i = 1; i < n; i++) {
            if(nums[i] > 0) 
                return i;
        }
        
        if(nums[0] > 0)
            return n;
        
        return n+1;
    }
};
