class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        if(nums.empty())
            return 0;
        
        int currPos = 0;
        
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] != nums[currPos]) {
                currPos++;
                nums[currPos] = nums[i];
            }
        }
        
        return currPos+1;
    }
};
