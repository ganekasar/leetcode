class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int p1 = 0, p2 = 0;
        
        while(p1 < nums.size()) {
            if(nums[p1] != val) {
                nums[p2] = nums[p1];
                p1++;
                p2++;
            } else 
                p1++;
        }
        
        return p2;
    }
};
