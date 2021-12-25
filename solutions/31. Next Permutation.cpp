class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index1 = nums.size() - 2;
        
        while(index1 >= 0 && nums[index1] >= nums[index1+1])
            index1--;
        
        if(index1 == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int index2 = nums.size() - 1;
        
        while(index2 > index1 && nums[index1] >= nums[index2])
            index2--;
    
        swap(nums[index1], nums[index2]);
        
        reverse(nums.begin()+index1+1, nums.end());
        
        return;
    }
};
    
​
